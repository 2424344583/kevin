#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include"treeStructure.h"
void printOut( FILE *fp, Node *node ) {
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0,-level);

  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}

void writeNode( FILE *fp, Node *node ) {

  int i;
  if( node->child[0] == NULL )
    printOut( fp, node );
  else {
    for ( i=0; i<4; ++i ) {
      writeNode( fp, node->child[i] );
    }
  }
  return;
}

void writeTree( Node *head ) {

  FILE *fp = fopen("quad.out","w");

  writeNode(fp,head);

  fclose(fp);

  return;
}
void destoryTree( Node *node ){
	int i;
	if(node->child[0] == NULL)
	free(node);
	else{
		for(i=0; i<4; ++i){
		destoryTree(node->child[i]);
		node->child[i]=NULL;	
		}
		free(node);
	}
	return;	
}
