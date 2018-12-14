#ifndef buildTree_h
#define buildTree_h
extern Node *makeNode( double x, double y, int level );
extern void makeChildren( Node *parent );
extern void growTree(Node *head);
extern void removeChildren(Node *parent);
double nodeValue( Node *node, double time );
double value( double x, double y, double time );
void flag(Node *node);
void findNode(Node *node);
void adapt(Node *head);          
extern int Add;
extern int Remove;
#endif


