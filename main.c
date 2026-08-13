//Danilo Pereira Lucas Antonelli Raimundo Amaral
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void menu(Lista* L) {
    int opcao, matricula;

    do {
        printf("\n=== SISTEMA DE MATRICULAS ===\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Buscar aluno\n");
        printf("4. Atualizar aluno\n");
        printf("5. Remover aluno\n");
        printf("0. Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar(L);
                salvar(L);
                break;
            case 2:
                listar(L);
                break;
            case 3:
                printf("Matricula: ");
                scanf("%d", &matricula);
                buscar(L, matricula);
                break;
            case 4:
                printf("Matricula: ");
                scanf("%d", &matricula);
                atualizar(L, matricula);
                salvar(L);
                break;
            case 5:
                printf("Matricula: ");
                scanf("%d", &matricula);
                remover(L, matricula);
                salvar(L);
                break;
            case 0:

                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while(opcao != 0);
}

int main() {
    Lista L;
    inicializar(&L);
    carregar(&L);  // carrega os dados do arquivo ao iniciar
    menu(&L);
    return 0;
}