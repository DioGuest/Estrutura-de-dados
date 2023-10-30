#include <stdio.h>
#include <string.h>
#include "tabela_hash.h"

char* tabela[TAMANHO_TABELA];

int hash(char* chave) {
    int soma = 0;
    for (int i = 0; i < strlen(chave); i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

char* hash_table_get(char* chave) {
    int indice = hash(chave);
    return tabela[indice];
}

void hash_table_put(char* chave, char* dado) {
    int indice = hash(chave);
    tabela[indice] = dado;
}

int hash_table_contains(char* chave) {
    int indice = hash(chave);
    return tabela[indice] != NULL;
}

void hash_table_remove(char* chave) {
    int indice = hash(chave);
    tabela[indice] = NULL;
}