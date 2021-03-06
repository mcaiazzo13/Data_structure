//----------------------------------------------GRAPH UNDIRECTED WITH LIST---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int num;
//----------------------------------------------------- STRUCT -----------------------------------------------------
struct node{
  int info;
  struct node *pNext;
} node;
typedef struct node *Node;

void makeGrafph(Node graph[]);
void insertCopyLink(Node graph[],Node nodeA,int infoB);
void insertLink(Node graph[],Node node,int index);
void print(Node node);

//----------------------------------------------------- MAKE GRAPH -----------------------------------------------------
void makeGraph(Node graph[]){
  Node ptr;
  int i,info;
  for(i=0;i<num;i++){
    printf("insert info : ");
    scanf("%d",&info);
    ptr = calloc(1,sizeof(node));
    ptr->info = info;
    graph[i] = ptr;
  }
}
//----------------------------------------------------- INSERT COPY LINK --------------------------------------------------
void insertCopyLink(Node graph[],Node nodeA, int infoB){
  int i;
  Node ptr;
  for(i=0;i<num;i++){
    if(graph[i]->info == infoB){
      ptr = calloc(1,sizeof(node));
      ptr->info = graph[i]->info;
      ptr->pNext = NULL;
      while(nodeA->pNext != NULL)
        nodeA = nodeA->pNext;
      nodeA->pNext = ptr;
      i = num;
    }
  }
}
//----------------------------------------------------- INSERT LINK -----------------------------------------------------
void insertLink(Node graph[],Node node,int index){
  Node ptr,ptr2;
  int i,info,choice;
  do{
    printf("Insert link to %d :\n",graph[index]->info);
    scanf("%d",&info);
    for(i=0;i<num;i++){
      if(graph[i]->info == info){
        ptr = calloc(1,sizeof(node)); 
        ptr->info = graph[i]->info;
        ptr->pNext = NULL;
        while(node->pNext != NULL)
          node = node->pNext;
        node->pNext = ptr;
        insertCopyLink(graph,graph[i],graph[index]->info);
        i = num;
      }
    }
    printf("\n1 -> Keep insert \t 2 -> Quit insert \n");
    scanf("%d",&choice);
  }while(choice != 2);
  
}
//----------------------------------------------------- PRINT -----------------------------------------------------
void print(Node node){
  while(node != NULL){
    printf("\t%d ->",node->info);
    node = node->pNext;
  }
  printf("\tNULL");
}
//----------------------------------------------------- MAIN -----------------------------------------------------
int main(int argc,char *argv[]){
  if(argc < 2){
    printf("Insert number of nodes.\n");
    exit(1);
  }
  int i;
  num = atoi(argv[1]);

  Node graph[num];
  for(i=0;i<num;i++)
    graph[i] = calloc(1,sizeof(Node));
  
  makeGraph(graph);

  for(i=0;i<num;i++)
    insertLink(graph,graph[i],i);

  sleep(1);
  for(i=0;i<num;i++){
    printf("\n");
    print(graph[i]);
  }
  return 0;
}
