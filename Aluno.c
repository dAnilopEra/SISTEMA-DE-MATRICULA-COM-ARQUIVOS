//Danilo Pereira Lucas Antonelli Raimundo Amaral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define ARQUIVO "alunos.txt"

void inicializar(Lista* L) {
    L->inicio = NULL;
}

// le o arquivo e carrega tudo na lista encadeada
void carregar(Lista* L) {
    FILE* f = fopen(ARQUIVO, "r");
    if (f == NULL) return;  // arquivo ainda nao existe, tudo bem

    Aluno a;
    while (fscanf(f, "%d;%99[^\n]\n", &a.matricula, a.nome) == 2) {
        // cria novo no dinamicamente
        No* novo = (No*)malloc(sizeof(No));
        novo->aluno = a;
        novo->prox = NULL;

        // insere no final da lista
        if (L->inicio == NULL) {
            L->inicio = novo;
        } else {
            No* atual = L->inicio;
            while (atual->prox != NULL) atual = atual->prox;
            atual->prox = novo;
        }
    }
    fclose(f);
}

// percorre a lista e salva tudo no arquivo
void salvar(Lista* L) {
    FILE* f = fopen(ARQUIVO, "w");  // w = reescreve do zero
    if (f == NULL) {
        printf("!Erro: nao foi possivel salvar\n");
        return;
    }
    No* atual = L->inicio;
    while (atual != NULL) {
        fprintf(f, "%d;%s\n", atual->aluno.matricula, atual->aluno.nome);
        atual = atual->prox;
    }
    fclose(f);
}

void cadastrar(Lista* L) {
    No* novo = (No*)malloc(sizeof(No));

    printf("Matricula: ");
    scanf("%d", &novo->aluno.matricula);

    // verifica se matricula ja existe
    No* atual = L->inicio;
    while (atual != NULL) {
        if (atual->aluno.matricula == novo->aluno.matricula) {
            printf("!Erro: matricula [%d] ja cadastrada\n", novo->aluno.matricula);
            free(novo);
            return;
        }
        atual = atual->prox;
    }

    printf("Nome: ");
    scanf(" %99[^\n]", novo->aluno.nome);
    novo->prox = NULL;

    // insere no final
    if (L->inicio == NULL) {
        L->inicio = novo;
    } else {
        atual = L->inicio;
        while (atual->prox != NULL) atual = atual->prox;
        atual->prox = novo;
    }
    printf("Aluno [%s] cadastrado com sucesso!\n", novo->aluno.nome);
}

void listar(Lista* L) {
    if (L->inicio == NULL) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    No* atual = L->inicio;
    int i = 1;
    printf("=== ALUNOS ===\n");
    while (atual != NULL) {
        printf("%d. Matricula: %d | Nome: %s\n", i, atual->aluno.matricula, atual->aluno.nome);
        atual = atual->prox;
        i++;
    }
}

void buscar(Lista* L, int matricula) {
    No* atual = L->inicio;
    while (atual != NULL) {
        if (atual->aluno.matricula == matricula) {
            printf("Aluno encontrado!\n");
            printf("Matricula: %d | Nome: %s\n", atual->aluno.matricula, atual->aluno.nome);
            return;
        }
        atual = atual->prox;
    }
    printf("!Erro: matricula [%d] nao encontrada\n", matricula);
}

void atualizar(Lista* L, int matricula) {
    No* atual = L->inicio;
    while (atual != NULL) {
        if (atual->aluno.matricula == matricula) {
            printf("Nome atual: %s\nNovo nome: ", atual->aluno.nome);
            scanf(" %99[^\n]", atual->aluno.nome);
            printf("Aluno atualizado com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }
    printf("!Erro: matricula [%d] nao encontrada\n", matricula);
}

void remover(Lista* L, int matricula) {
    No* atual = L->inicio;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->aluno.matricula == matricula) {
            if (anterior == NULL) {
                L->inicio = atual->prox;  // era o primeiro
            } else {
                anterior->prox = atual->prox;  // pula o no removido
            }
            free(atual);  // libera a memoria
            printf("Aluno [%d] removido com sucesso!\n", matricula);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("!Erro: matricula [%d] nao encontrada\n", matricula);
}