// ------------------------------------------DIRECTED GRAPH ADJ MATRIX BFS AND DFS----------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// --------------------------------------------------- NODE STRUCT--------------------------------------------------
struct node{
  int name;
  int color;
};
typedef struct node Tnode;
// --------------------------------------------------- MATRIX ----------------------------------------------------------
int **matrix;
int n;
int head = -1,tail = -1;
// --------------------------------------------------- FUNCTIONS----------------------------------------------------------
// queue
int isEmpty();
void addQueue(int nodeIndex,int queue[]);
int extractQueue(int queue[]);
void findLink(Tnode *nodes[],int indexNode,int queue[]);
 
char readInput();
int charToIndex(Tnode *nodes[],char choice);
// insert
void insertLink(Tnode *nodes[]);
// remove
void removeLink(Tnode *nodes[]);
// print
void printGraphBFS(Tnode *nodes[],int source);
void printGraphDFS(Tnode *nodes[],int node);
// --------------------------------------------------- IS EMPTY----------------------------------------------------------
int isEmpty(){
  if(head == -1 || head > tail)
    return 1;
  else
    return 0;
}
// --------------------------------------------------- READ INPUT----------------------------------------------------------
char readInput(){
  int name;
  printf("\nInsert node name :");
  scanf("%d",&name);
  fflush(stdin);
  return name;
}
// --------------------------------------------------- INSERT LINK----------------------------------------------------------
void insertLink(Tnode *nodes[]){
  int node1,node2;
  printf("->"); node1 = readInput();
  printf("->"); node2 = readInput();
  matrix[node1][node2] = 1;
}
// ---------------------------------------------------REMOVE LINK---------------------------------------------------------
void removeLink(Tnode *nodes[]){
  int node1,node2;
  printf("->"); node1 = readInput();
  printf("->"); node2 = readInput();
  matrix[node1][node2] = 0;
}
// --------------------------------------------------- ADD QUEUE---------------------------------------------------------
void addQueue(int nodeIndex,int queue[]){
  if(tail == n-1)
    printf("error add\n");
  else{
    if(head == -1)
      head = 0;
    tail = tail+1;
    queue[tail] = nodeIndex;
  }
}
// --------------------------------------------------- EXTRACT QUEUE-------------------------------------------------------
int extractQueue(int queue[]){
  int extract;
  if(head == -1 || head > tail){
    printf("error extract %d %d\n",head,tail);
    exit(1);
  }
  extract = queue[head];
  head = head+1;
  return extract;
}
// --------------------------------------------------- FIND LINK--------------------------------------------------------
void findLink(Tnode *nodes[],int indexNode,int queue[]){
  int i;
  for(i=0;i<n;i++){
    if(matrix[indexNode][i] == 1 && nodes[i]->color == 0){
      nodes[i]->color = 1;
      addQueue(i,queue);
    }
  }
}
// --------------------------------------------------- PRINT GRAPH BFS---------------------------------------------------
// in this version i use integer because is simpler than use pointer
// the result is the same
void printGraphBFS(Tnode *nodes[],int source){
  int nodeIndex,i;
  int queue[n];
  for(i=0;i<n;i++){
    nodes[i]->color = 0;
  }
  nodes[source]->color = 1;
  addQueue(source,queue);
  while(!isEmpty()){
    nodeIndex = extractQueue(queue);
    findLink(nodes,nodeIndex,queue);
    nodes[nodeIndex]->color = 2;
    sleep(1);
    printf("Nodo visitato BLACK %d\n",nodes[nodeIndex]->name);
  }
}
// --------------------------------------------------- PRINT GRAPH DFS-----------------------------------------------------
void printGraphDFS(Tnode *nodes[],int node){
  int j;
  printf("Nodo visitato %d\n",node);
  nodes[node]->color = 1;
  for (j = 0; j < n; j++){
    if(!nodes[j]->color && matrix[node][j] == 1){
      printGraphDFS(nodes,j);
   }
  }
}


// --------------------------------------------------- MAIN----------------------------------------------------------
int main(int argc,char *argv[]){
  int i;
  n = atoi(argv[1]);
  fflush(stdin);
  //--------------------------------------- MATRIX
  matrix = (int**)calloc(n,sizeof(int*));
  for(i=0;i<n;i++){
    matrix[i] = (int*)calloc(n,sizeof(int*));
  }
  // -------------------------------------- NODES
  Tnode *node[n];
  for(i=0;i<n;i++){
    node[i] = (Tnode*)malloc(sizeof(Tnode));
    node[i]->name = i;
  }
  /* now the matrix looks like that
       A B C D ...
     A 0 0 0 0
     B 0 0 0 0
     C 0 0 0 0
     D 0 0 0 0
     .
     .
     .
  */
 // using this makes all the things simpler because the link are already done
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
 
  int choice,source;
  do{
    printf("\n1.insert link \n2.remove link \n3.BFS \n4.DFS \n");
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice){
    case 1: // insert new LINK
      insertLink(node);
      break;
    case 2: // remove LINK
      removeLink(node);
      break;
    case 3: // print matrix BFS
      printf("Insert source :");
      scanf("%d",&source);
      printGraphBFS(node,source);
      break;
    case 4: // print matrix DFS
      printf("insert source :");
      scanf("%d",&source);                                                                                                                                                                    
      for(i=0;i<n;i++)
        node[i]->color = 0;
      printGraphDFS(node,source);
      break;
    }
  }while(choice != 5);
  return 0;
  }
