#ifndef treeStructure_h
#define treeStructure_h
struct qnode {
  int flag; 
  int level;
  double xy[2];
  struct qnode *child[4];
};
typedef struct qnode Node; 
#endif
