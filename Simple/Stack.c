#include <stdio.h>
#include <stdlib.h>
//--------------------------------------------------------STACK-------------------------------------------------------

struct nodo{
    int info;
    struct nodo *pNext;
};
typedef struct nodo Nodo;

Nodo *testa = NULL;
// ------------------------------- insert the head of the stack
void inserimento_testa(int info){
    Nodo *nodoNuovo;
    nodoNuovo = malloc(sizeof(Nodo));
    nodoNuovo->info = info;
    nodoNuovo->pNext = NULL;
    
    if(testa == NULL){
        testa = nodoNuovo;
    }
    else{
        nodoNuovo->pNext = testa;
        testa = nodoNuovo;
    }
}
// ------------------------------- remove the stack's head
void eliminazione_testa(){
    if(testa == NULL){
        puts("Lo stack è vuoto.");
    }
    else{
        Nodo *pt;
        pt = testa->pNext;
        free(testa);
        testa = pt;
    }
}
// ------------------------------- print the stack
void visita(){
    if(testa == NULL){
        puts("Stack vuoto");
    }
    else{
        Nodo *pt;
        pt = testa;
        do{
            printf("Elem ->%d \n",pt->info);
            pt = pt->pNext;
            
        }while(pt != NULL);
    }
}

int main(){
    int scelta,dato;
    do{
        puts("\n MENU \n\n1.insert \n2.remove \n3.print \n");
        scanf("%d",&scelta);
        switch (scelta) {
            case 1: // ins
                puts("Inserire dato");
                scanf("%d",&dato);
                inserimento_testa(dato);
                break;
            case 2: // elim
                eliminazione_testa();
                break;
            case 3: // vis
                visita();
                break;
            default: printf("Riprova");
                break;
        }
    }while(scelta != 4);
}
