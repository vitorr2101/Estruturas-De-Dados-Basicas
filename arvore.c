#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
   struct node* esq;
   struct node* dir;
   char nome[50];
   int idade;
} node;

void free_tree(node *no) {
    if (no == NULL) {
        return;
    }
    free_tree(no->esq);
    free_tree(no->dir);
    free(no);
}

node *insert(node *no, char *name, int x){

    if(no == NULL){
        node *newNode = (node *)malloc(sizeof(node));
        if (!newNode) {
            printf("Erro de alocação de memória!\n");
            return NULL;
        }
        
        strcpy(newNode->nome, name);
        newNode->idade = x;
        newNode->esq = NULL;
        newNode->dir = NULL;
        return newNode;
    }
        
    if(no->idade > x){
        no->esq = insert(no->esq, name, x);
    }
    else {
        no->dir = insert(no->dir, name, x);
    }
    return no;
}

void print_list(node *no){
    if (no != NULL) {
        print_list(no->esq);
        printf("(%s, %d) ", no->nome, no->idade);
        print_list(no->dir);
    }
}

void print_filhos_ana(node *no){
    if (no != NULL) {

        if(strcmp(no->nome,"Ana") == 0){
            printf("(%s, %d) ", no->nome, no->idade);
            print_list(no->esq);
            print_list(no->dir);
        }
        else{
            print_filhos_ana(no->dir);
            print_filhos_ana(no->esq);
        }
    }
}

int main(){
    node *no = NULL;
    int option;

    do {
        printf("\nMenu:\n");
        printf("1. Criar/Inserir na Árvore\n");
        printf("2. Printar Árvore\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
            
            if (no != NULL) {
                free_tree(no);
                no = NULL;
            }
            
            char *names[] = {"Elísio", "Carlos", "Ana", "Thomas", "Joana"};
            int idades[] = {63, 31, 25, 5, 5};

            for (int i = 0; i < 5; i++)
            {
                no = insert(no, names[i], idades[i]);
            }
            break;
            case 2:
                print_list(no);
                printf("\n");
                print_filhos_ana(no);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 3);

    free_tree(no);

    return 0;
}

