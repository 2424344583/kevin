#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include"treeStructure.h"
#include"buildTree.h"
#include"writeTree.h"

int main( int argc, char **argv ) {
  Add=0;
  Remove=0;
  Node *head;
  head = makeNode( 0.0,0.0, 0 );
  makeChildren( head );
  growTree(head);
  growTree(head);
  adapt(head);
  writeTree(head );	
  return 0;
}
