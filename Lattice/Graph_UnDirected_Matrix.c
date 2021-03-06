//-----------------------------------------UNDIRECTED GRAPH MATRIX BFS AND DFS VISIT----------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int n;
int **matrix;
//---------------------------------------- STRUCT FOR NODES
struct node{
  int name;
  int color; // 0: white | 1: grey | 2: black
};
typedef struct node Tnode;
int head = -1,tail = -1;
//---------------------------------------- FUNCTIONS
int readInput();
// queue for BFS
void addQueue(int node,int queue[]);
int extractQueue(int queue[]);
int isEmpty();
void verifyAdj(int node,Tnode *nodes[],int queue[]);
// insert
void insertLink();
// remove
void removeLink();
void showMatrix();
// visit
void visitBFS(Tnode *nodes[],int node);
void visitDFS(Tnode *nodes[],int node);
//------------------------------------------------------READ INPUT----------------------------------------------------
int readInput(){
  int node;
  printf("Insert node :");
  scanf("%d",&node);
  return node;
}
//-------------------------------------------------------INSERT-------------------------------------------------------
void insertLink(){
  int node1,node2;
  node1 = readInput();
  node2 = readInput();
  matrix[node1][node2] = 1; 
  matrix[node2][node1] = 1;
}
//-------------------------------------------------------REMOVE-------------------------------------------------------
void removeLink(){
  int node1,node2;
  node1 = readInput();
  node2 = readInput();
  matrix[node1][node2] = 0;
  matrix[node1][node2] = 0;
}
//------------------------------------------------------- SHOW MATRIX-------------------------------------------------------
void showMatrix(){
  int i,j;
  for(i=0;i<n;i++){
    printf("\n");
    for(j=0;j<n;j++){
      printf("%d \t",matrix[i][j]);
    }
  }
}
//------------------------------------------------------- VISIT DFS-------------------------------------------------------
void visitDFS(Tnode *nodes[],int node){
  int j;
  printf("Node visited %d \n",node);
  nodes[node]->color = 1;
  for(j=0;j<n;j++){
    if(!nodes[j]->color && matrix[node][j] ==1){
      visitDFS(nodes,j);
    }
  }
}
//------------------------------------------------------- IS EMPTY-------------------------------------------------------
int isEmpty(){
  if(head == -1 || head > tail)
    return 1;
  else
    return 0;
}
//-------------------------------------------------------ADD QUEUE -------------------------------------------------------
void addQueue(int node,int queue[]){
  if(tail== n-1) 
    exit(1);
  else if(head == -1)
    head = 0;
  tail = tail+1;
  queue[tail] = node;
}
//-------------------------------------------------------EXTRACT QUEUE-------------------------------------------------------
int extractQueue(int queue[]){
  int node;
  if(head ==-1 || head > tail)
    exit(1);
  node = queue[head];
  head = head+1;
  return node;
}
//-------------------------------------------------------VERIFY ADJ-------------------------------------------------------
void verifyAdj(int node,Tnode *nodes[],int queue[]){
  int i;
  for(i=0;i<n;i++){
    if(matrix[node][i] == 1 && nodes[i]->color == 0){
      nodes[i]->color = 1; // now is grey
      addQueue(i,queue);
    }
  }
}
//-------------------------------------------------------VISIT BFS-------------------------------------------------------
void visitBFS(Tnode *nodes[],int source){
  int queue[n];
  int i,node;
  for(i=0;i<n;i++){
    nodes[i]->color = 0; // all white
  }
  nodes[source]->color = 1; // source grey
  addQueue(source,queue);
  while(!isEmpty()){
    node = extractQueue(queue);
    verifyAdj(node,nodes,queue);
    nodes[node]->color = 2; // now is black
    sleep(1);
    printf("Node %d\n",node);
  }
}
//-------------------------------------------------------MAIN-------------------------------------------------------
int main(int argc, char *argv[]){
  if(argc <2){
    printf("Write the number of Edges\n");
    exit(1);
  }
  n = atoi(argv[1]);
  int i;
  Tnode *nodes[n];
  for(i=0;i<n;i++){
    nodes[i] = (Tnode*)malloc(sizeof(Tnode));
    nodes[i]->name = i;
    nodes[i]->color = 0;
  }

  matrix = (int**)calloc(n,sizeof(int*));
  for(i=0;i<n;i++){
    matrix[i] = (int*)calloc(n,sizeof(int*));
  }
  
  matrix[0][1] = 1;
  matrix[0][3] = 1;
  
  matrix[1][4] = 1; 
  matrix[1][2] = 1; 

  matrix[2][1] = 1; 
  matrix[2][0] = 1; 
  
  matrix[3][2] = 1; 
  matrix[3][4] = 1; 
  
  matrix[4][3] = 1; 
   matrix[4][1] = 1; 
  matrix[4][0] = 1; 
  // inverse
  matrix[0][2] = 1;
  matrix[0][4] = 1;

  matrix[2][3] = 1;
  matrix[1][0] = 1;
  matrix[3][0] = 1;

  showMatrix();
  printf("\n DFS \n");
  visitDFS(nodes,4);

  printf("\n BFS \n");
  visitBFS(nodes,2);
  return 0;
}
