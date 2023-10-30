#include <stdio.h>
#include <string.h>
#include "tabela_hash.h"

int main() {
    char chave[100];
    char dado[100];

    while (1) {
        printf("Digite o comando (get, put, contains, remove, sair): ");
        scanf("%s", chave);

        if (strcmp(chave, "sair") == 0) {
            break;
        }

        if (strcmp(chave, "get") == 0) {
            printf("Digite a chave: ");
            scanf("%s", chave);
            char* valor = hash_table_get(chave);
            if (valor != NULL) {
                printf("Valor: %s\n", valor);
            } else {
                printf("Chave não encontrada\n");
            }
        } else if (strcmp(chave, "put") == 0) {
            printf("Digite a chave: ");
            scanf("%s", chave);
            printf("Digite o valor: ");
            scanf("%s", dado);
            hash_table_put(chave, dado);
            printf("Valor armazenado com sucesso\n");
        } else if (strcmp(chave, "contains") == 0) {
            printf("Digite a chave: ");
            scanf("%s", chave);
            int contem = hash_table_contains(chave);
            if (contem) {
                printf("Chave encontrada\n");
            } else {
                printf("Chave não encontrada\n");
            }
        } else if (strcmp(chave, "remove") == 0) {
            printf("Digite a chave: ");
            scanf("%s", chave);
            hash_table_remove(chave);
            printf("Chave removida\n");
        } else {
            printf("Comando inválido\n");
        }
    }

    return 0;
}