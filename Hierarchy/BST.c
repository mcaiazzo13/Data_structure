//---------------------------------------BINARY SEARCH TREE WITH REMOVE FUNCTION---------------------------------
#include <stdio.h>
#include <stdlib.h>
//-------------------------------------------------------STRUCT--------------------------------------------------
// struct for BTS's information node (it is a struct because every node can have more informations)
struct information{
  int num;
};
typedef struct information Tinfo;
//struct for BTS's node
struct node{
  Tinfo info;
  struct node *Dx;
  struct node *Sx;
};
typedef struct node Tnode;
typedef Tnode *Tree; // *Tree is a pointer so i don't use double pointer

//-------------------------------------------------------FUNCTIONS--------------------------------------------------
Tree makeBTS(); 
Tinfo readInput(); 
void printInfo(); 
Tree destroyBTS(Tree bts); 
// insert
Tree insertNode(Tree bts,Tinfo info); 
void insertNewNode(Tree bts,Tinfo info);
// search
Tnode *search(Tree bts,Tinfo info); 
void searchingNode(Tree bts,Tinfo info);
// remove
Tnode removeNode(Tree bts,Tinfo info); // no
Tnode *searchMin(Tree bts); // no
void destroyNode(Tnode *node);
// print
void printBTS(Tree bts);x

//-------------------------------------------------------SEARCHING NODE---------------------------------------------
void searchingNode(Tree bts,Tinfo info){
  Tnode *ptr;
  info = readInput(); // insert the node to find
  ptr = search(bts,info); //  find the node
  if(search == NULL)
    printf("Not present\n");
  else
    printf("Is present\n");
}
//---------------------------------------------------INSERT NEW NODE--------------------------------------------------
void insertNewNode(Tree bts, Tinfo info){
  info = readInput();
  bts = insertNode(bts,info);
}
//-------------------------------------------------------CREATE BTS--------------------------------------------------
Tree makeBTS(){
  return NULL;
}

//-------------------------------------------------------DESTROY SINGLE NODE-----------------------------------------
void destroyNode(Tnode *node){
  free(node);
}
//-------------------------------------------------------INSERT NODE--------------------------------------------------
Tree insertNode(Tree bts,Tinfo info){
  if(bts == NULL){
    // insert the root node
    Tnode *newNode;
    newNode = (Tnode*)malloc(sizeof(Tnode));
    newNode->info = info;
    newNode->Dx = NULL;
    newNode->Sx = NULL;
  }else if(info.num <= bts->info.num){
    // bts is not NULL so there is a control on the root's info and input's info
    bts->Sx = insertNode(bts->Sx,info);
    return bts;
  }else{
    bts->Dx = insertNode(bts->Dx,info);
    return bts;
  }
}
//-------------------------------------------------------READ FROM INPUT--------------------------------------------------
Tinfo readInput(){
  Tinfo info;
  printf("Inserire valore:");
  scanf("%d",&(info.num));
  return info;
}
//-------------------------------------------------------PRINT THE NODE INFO--------------------------------------------------
void printInfo(Tinfo info){
  printf("%d \n",info.num);
}
//-------------------------------------------------------PRINT BTS--------------------------------------------------
void printBTS(Tree bts){
  if(bts != NULL){
    printBTS(bts->Sx);
    printInfo(bts->info);
    printBTS(bts->Dx);
  }
}
//-------------------------------------------------------DESTROY NODE--------------------------------------------------
Tree destroyTree(Tree bts){
  if(bts == NULL) // the BTS does not exist
    return NULL;
  else if(bts->Sx == NULL && bts->Dx == NULL){ // only the root exist
    free(bts);
    return NULL;
  }else{ // the BTS has at least one Sx and one Dx
    bts->Sx = destroyTree(bts->Sx);
    bts->Dx = destroyTree(bts->Dx);
    destroyNode(bts);
    return NULL;
  }
}
//-------------------------------------------------------SEARCH--------------------------------------------------
Tnode *search(Tree bts, Tinfo info){
  if(bts == NULL || bts->info.num == info.num) // if the bts is NULL or the info in searching is root's info
    return bts;
  else{
    // this is a recursive way to search an info into a bts
    if(info.num <= bts->info.num){
      return search(bts->Sx,info);
    }else{
      return search(bts->Dx,info);
    }
  }
}
//----------------------------------------------SEARCH MIN FOR REMOVE------------------------------------------
Tnode *searchMin(Tree bts){                                                                                                                                                                     
  Tree min;                                                                                                                                                                                     
  if (bts ==NULL) // if the bts is NULL                                                                                                                                                         
    return NULL                                                                                                                                                                                 
    else if(bts->Sx == NULL) // if the bts does not have Sx child                                                                                                                               
      return NULL;                                                                                                                                                                              
    else{                                                                                                                                                                                       
      min = searchMin(bts->Sx);                                                                                                                                                                 
      return min;                                                                                                                                                                               
    }                                                                                                                                                                                           
}    
//----------------------------------------------REMOVING NODE----------------------------------------------------
void removingNode(Tree bts,Tinfo info){                                                                                                                                                         
  info = readInput();                                                                                                                                                                           
  bts = removeNode(bts,info);                                                                                                                                                                   
}  
//---------------------------------------------------REMOVE NODE--------------------------------------------------
Tree removeNode(Tree bts, Tinfo info){
  if (bts == NULL) // if the bts is null                                                                                                                                                        
    return NULL;                                                                                                                                                                                
  else if(info.num < bts->info.num){ // if the info is lower than my actual bts node                                                                                                            
    bts->Sx = removeNode(bts->Sx,info);                                                                                                                                                         
    return bts;                                                                                                                                                                                 
  }else if(info.num > bts->info.num){ // if the info is higher than my actual bts node                                                                                                          
    bts->Dx = removeNode(bts->Dx,info);                                                                                                                                                         
    return bts;                                                                                                                                                                                 
  }else{                                                                                                                                                                                        
    if(bts->Dx == NULL && bts->Sx == NULL){ //  i found the node and if it should have both child null                                                                                          
      destroyNode(bts);                                                                                                                                                                         
      return NULL;                                                                                                                                                                              
    }                                                                                                                                                                                           
    else if(bts->Dx == NULL){ // if only the Dx child is NULL                                                                                                                                   
      Tree p;                                                                                                                                                                                   
      p = bts->Sx;                                                                                                                                                                              
      destroyNode(bts);                                                                                                                                                                         
      return p;                                                                                                                                                                                 
    }else if(bts->Sx == NULL){ // if only the Sx child is NULL                                                                                                                                  
      Tree p;                                                                                                                                                                                   
      p = bts->Dx;                                                                                                                                                                              
      destroyNode(bts);                                                                                                                                                                         
      return p;                                                                                                                                                                                 
    }                                                                                                                                                                                           
    // here we have to storage the linking                                                                                                                                                      
    // minDx is useful for finding the minimun of the right tree and change with the node to remove                                                                                             
    Tree minDx;                                                                                                                                                                                 
    minDx = searchMin(bts->Dx);                                                                                                                                                                 
    bts->info = minDx->info;                                                                                                                                                                    
    bts->Dx=removeNode(bts->Dx,minDx->info);                                                                                                                                                    
    return bts;                                                                                                                                                                                 
  }                                                                                                                                                                                             
}       
//-------------------------------------------------------MAIN--------------------------------------------------
int main(){
  
  Tree bts; // binary search tree
  Tinfo info; // info that i use in main
  int i,dim,choice;

  // making the BTS
  bts = makeBTS(); 

  printf("insert the initial number of nodes : ");
  scanf("%d",&dim);
  for(i=0;i<dim;i++){
    info = readInput();
    bts = insertNode(bts,info);
  }
  do{
    printf("1.insert \n 2.search \n 3.remove \n 4.print \n 5.exit \n");
    scanf("%d",&choice); 
    switch(choice){
    case 1:
      insertNewNode(bts,info);
      break;
    case 2:
      searchingNode(bts,info);
      break;
    case 3:
      removingNode(bts,info);
    break;
    case 4:
      printBTS(bts);
      break;
    default:
      printf("Not in the list\n");
      break;
    }
  }while(choice != 5);
  printf("You pressed 5. Exit.\n");
  return 0;
}
