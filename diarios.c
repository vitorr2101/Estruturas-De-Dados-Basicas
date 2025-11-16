#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diarios
{
   struct diarios* p;
   char date[50];
} diarios;

void empilha(diarios **diario, const char *lista_diarios){
    
    diarios *newDiario = (diarios *)malloc(sizeof(diarios));
    
    if (!newDiario) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    
    strcpy(newDiario->date, lista_diarios);
    newDiario->p = *diario;
    *diario = newDiario;   
}

void desempilha(diarios *diario){
    if (diario == NULL) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Pilha: ");
    while(diario != NULL){
        printf("%s -> ", diario->date);
        diario = diario->p;
    }
    printf("NULL\n");
}

int main(){
    diarios *diario = NULL;
    int option;

    do {
        printf("\nMenu:\n");
        printf("1. Criar/Inserir na pilha de diários\n");
        printf("2. Printar pilha de diários\n");
        printf("3. Printar nome do diário do topo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
            static const char *diarios[] = {"Diário 1983", "Diário 1986", "Diário 1989", "Diário 1992"};
            
                for (int i = 0; i < 4; i++) // usamos um valor fixo pois sabemos de antemão a quantidade de diários
                {
                    empilha(&diario, diarios[i]);
                    printf("Nó inserido!\n");
                }
                break;
            case 2:
                desempilha(diario);
                break;
            case 3:
                if (diario != NULL) {
                    printf("Esse é o primeiro diário: %s\n", diario->date);
                } else {
                    printf("A pilha de diários está vazia.\n");
                }
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 4);

    diarios *temp;
    while (diario != NULL) {
        temp = diario;
        
        printf("%s\n", temp->date);
        
        diario = diario->p;
        
        free(temp);
    }

    return 0;
}
