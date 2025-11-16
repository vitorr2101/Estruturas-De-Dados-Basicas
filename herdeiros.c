#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct herdeiros
{
   struct herdeiros* p;
   char name[50];
} herdeiros;

void insert(herdeiros **familia, const char *familiar){
    
    herdeiros *newHerdeiro = (herdeiros *)malloc(sizeof(herdeiros));
    
    if (!newHerdeiro) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    
    strcpy(newHerdeiro->name, familiar);
    newHerdeiro->p = NULL;     
    
    if(*familia == NULL){
        *familia = newHerdeiro;
    }    
    else {
        herdeiros *temp = *familia;
        while(temp->p != NULL){
            temp = temp->p;
        }
        temp->p = newHerdeiro;
    }
}

void print_list(herdeiros *familiar){
    if (familiar == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    printf("Lista: ");
    while(familiar != NULL){
        printf("%s -> ", familiar->name);
        familiar = familiar->p;
    }
    printf("NULL\n");
}

int main(){
    herdeiros *familiar = NULL;
    int option;

    do {
        printf("\nMenu:\n");
        printf("1. Criar/Inserir na lista de investigados\n");
        printf("2. Printar lista de familiares\n");
        printf("3. Printar primeiro da fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
            static const char *familiares[] = {"Carlos", "Joana", "Thomas", "Ana"};
            
                for (int i = 0; i < 4; i++) // usamos um valor fixo pois sabemos de antemão a quantidade de investigados
                {
                    insert(&familiar, familiares[i]);
                    printf("Nó inserido!\n");
                }
                break;
            case 2:
                print_list(familiar);
                break;
            case 3:
                if (familiar != NULL) {
                    printf("Esse é o primeiro familiar: %s\n", familiar->name);
                } else {
                    printf("A lista de familiares está vazia.\n");
                }
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 4);

    // Liberar a memória alocada para a lista
    herdeiros *temp;
    while (familiar != NULL) {
        temp = familiar;
        familiar = familiar->p;
        free(temp);
    }

    return 0;
}
