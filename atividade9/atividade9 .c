#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    float valor;
    struct No* proximo;
} No;

void lista_inserir_no_ordenado(No* lista, No* novo) {
    No* atual = lista;
    No* anterior = NULL;

    while (atual != NULL && atual->valor < novo->valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        novo->proximo = lista;
        lista = novo;
    } else {
        anterior->proximo = novo;
        novo->proximo = atual;
    }
}

int main() {
    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    char linha[50];
    float numero;

    clock_t inicio = clock();

    while (fgets(linha, sizeof(linha), arquivo)) {
        numero = atof(linha);

        No* novo = (No*)malloc(sizeof(No));
        novo->valor = numero;
        novo->proximo = NULL;

        lista_inserir_no_ordenado(lista_ordenada, novo);
        // Para a lista não ordenada, você pode apenas adicionar o nó no final.
        novo = (No*)malloc(sizeof(No));
        novo->valor = numero;
        novo->proximo = NULL;
        if (lista_nao_ordenada == NULL) {
            lista_nao_ordenada = novo;
        } else {
            No* atual = lista_nao_ordenada;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novo;
        }
    }

    clock_t fim = clock();
    double tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo total para inserção ordenada: %lf segundos\n", tempo_total);

    // Você pode calcular o tempo médio dividindo o tempo total pelo número de elementos na lista.

    fclose(arquivo);

    return 0;
}
