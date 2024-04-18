#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//----STRUCT DA PILHA----//

typedef struct {
    char adicionar[4];
} Genetico;

typedef struct no {
    Genetico g;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Pilha;

//--- CODIGO DA FILA ----//

typedef struct node {
    int posi_cao;
    struct node *next;
} Node;

//----STRUCT DA LISTA----//

typedef struct no3 {
    char resultado[20];
    struct no3 *proximo3;
} No3;

//----CODIGO DA PILHA----//

void criar(Pilha *g) {
    g->inicio = NULL;
    g->tam = 0;
}

void empilhar(Pilha *g, char *adicionar) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo) {
        strcpy(novo->g.adicionar, adicionar);
        novo->proximo = g->inicio;
        g->inicio = novo;
        g->tam++;
    } else {
        printf("\nErro ao alocar memória.\n");
    }
}

No* desempilhar(Pilha *g) {
    if (g->inicio) {
        No *remover = g->inicio;
        g->inicio = remover->proximo;
        g->tam--;
        return remover;
    } else {
        printf("\nPilha vazia.\n");
    }
    return NULL;
}

void imprimirmypilha(Pilha *g) {
    No *aux = g->inicio;
    while (aux) {
        printf("\nProteina: %s\n", aux->g.adicionar);
        aux = aux->proximo;
    }
}

//----CODIGO DA FILA----//

void inserir_na_fila(Node **fila, int posi_cao) {
    Node *aux2, *maisnovo2 = (Node*) malloc(sizeof(Node));
    if (maisnovo2) {
        maisnovo2->posi_cao = posi_cao;
        maisnovo2->next = NULL;
        if (*fila == NULL) {
            *fila = maisnovo2;
        } else {
            aux2 = *fila;
            while (aux2->next) {
                aux2 = aux2->next;
            }
            aux2->next = maisnovo2;
        }
    } else {
        printf("\nErro ao alocar memória.\n");
    }
}

void imprimirmyfila(Node *fila) {
    Node *aux = fila;
    while (aux) {
        printf("\nFila: %d \n", aux->posi_cao);
        aux = aux->next;
    }
    printf("\n");
}

//----CODIGO DA LISTA----//

void inserir_no_fim(No3 **lista, char *proteina) {
    No3 *aux3, *novo3 = (No3*) malloc(sizeof(No3));

    if (novo3) {
        strcpy(novo3->resultado, proteina);
        novo3->proximo3 = NULL;

        if (*lista == NULL) {
            *lista = novo3;
        } else {
            aux3 = *lista;
            while (aux3->proximo3) {
                aux3 = aux3->proximo3;
            }
            aux3->proximo3 = novo3;
        }
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

void imprimirmyLista(No3 *no3) {
    printf("\nLista: ");
    while (no3) {
        printf("\n%s ", no3->resultado);
        no3 = no3->proximo3;
    }

    printf("\n\n");
}

//------------------------------------------------------------
//|                      CODIGO PRINCIPAL                    |
//-----------------------------------------------------------

int main() {
    
    //----PILHA----//
    
    No *remover;
    Pilha g;
    int opcao;
    
    //----FILA----//
    
    Node *r, *fila = NULL;
    int posi_cao;
    
    //----LISTA----//
    
    No3 *lista = NULL;

    criar(&g);

    int i, indice;
    char linha[100], adicionar[4];
    char aaa[] = "AAA", cgt[] = "CGT", gga[] = "GGA";
    char lisina[] = "lisina", arginina[] = "arginina", glicina[] = "glicina";

    printf("Digite qualquer sequencia: ");
    scanf("%s", linha);

    indice = strlen(linha);

    for (i = 0; i < indice - 2; i++) {
        memcpy(adicionar, &linha[i], 3);
        
        printf("%s\n", adicionar);

        if (strcmp(aaa, adicionar) == 0) {
            
            empilhar(&g, adicionar);
            inserir_na_fila(&fila, i);
            inserir_no_fim(&lista, lisina);
            i = i + 2;
        }
        if (strcmp(cgt, adicionar) == 0) {
            
            empilhar(&g, adicionar);
            inserir_na_fila(&fila, i);
            inserir_no_fim(&lista, arginina);
            i = i + 2;
        }
        if (strcmp(gga, adicionar) == 0) {
            printf("Encontrou GGA \n");
            empilhar(&g, adicionar);
            inserir_na_fila(&fila, i);
            inserir_no_fim(&lista, glicina);
            i = i + 2;
        }

        imprimirmypilha(&g);
        imprimirmyfila(fila);
        imprimirmyLista(lista);
        
    }

    return 0;
}
