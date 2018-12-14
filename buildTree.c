#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
int Add;
int Remove;
Node *makeNode( double x, double y, int level )
{
  int i;

  Node *node = (Node *)malloc(sizeof(Node));
  node->level = level;
  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;
    
  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );
  return;
}
void growTree(Node *parent){
	int i;
	if(!parent){
		return;
	}
	for(i = 0; i < 4; i++){
		growTree(parent->child[i]);
}
	if(parent->child[0] == NULL && parent->child[1] == NULL && parent->child[2] == NULL && parent->child[3] == NULL){
		makeChildren(parent);
	}
	return;
}
void removeChildren(Node *parent){
	int i;
	for(i = 0; i < 4; i++){
		parent->child[i]=NULL; 
		free(parent->child[i]);	
	}
	return;	 
}
double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}
double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];
  double h = pow(2.0,-level);
  return( value( x+0.5*h, y+0.5*h, time ) );
}

void flag(Node *node){
	int i;
	double a;
	node->flag=0;
	if(node->child[0]==NULL){
	a=nodeValue(node,0.0);
		if(a>0.5){
			node->flag=1;
		}
		else if (a<-0.5){
			node->flag=-1;
		}
	}
	else{
		for(i=0;i<4;i++){
			flag(node->child[i]);
		}
	}
	return;	
}

void findNode(Node *node){
	int i;
	int maxLevel=6;
	int r=0;
	if(node->child[0]==NULL){
		if(node->level<maxLevel&&node->flag==1){
			Add+=4;
			makeChildren(node);
		}
	}
	else if (node->child[0]!=NULL){
		for (i=0;i<4;++i){
			if(node->child[i]->flag==-1){
				r+=1;
			}
		}
		if(r==4){
			Remove+=4;
			removeChildren(node);
		}
		else{
			for(i=0;i<4;++i){
				findNode(node->child[i]);
			}
		}
	}
	return;  
}
void adapt(Node *node){
	Add=-1;
	Remove=Add;
	while(Add!=0||Remove!=0){
		Add=0;
		Remove=Add;
		flag(node);
		findNode(node);
		printf("The number of nodes that add is %i\n",Add);
  		printf("The number of nodes that remove is %i\n",Remove);
	}
}


