//Danilo Pereira Lucas Antonelli Raimundo Amaral
#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int matricula;
    char nome[100];
} Aluno;

typedef struct No {
    Aluno aluno;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
} Lista;

void inicializar(Lista* L);
void carregar(Lista* L);
void salvar(Lista* L);
void cadastrar(Lista* L);
void listar(Lista* L);
void buscar(Lista* L, int matricula);
void atualizar(Lista* L, int matricula);
void remover(Lista* L, int matricula);

#endif