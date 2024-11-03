/*---------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular            *
*          Prof. Carlos Veríssimo                          *                                             *                                                          *
*----------------------------------------------------------*
* Objetivo do Programa: N2-5-Utilizando ponteiros          * 
* Data - 01/11/2024                                        * 
* Autor: Milena Mitie                                      *
*---------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    int quantidadeEmEstoque;
    double valorDoProduto;
} Produto;

void incluirProduto(Produto *produtos, int *totalProdutos);
void consultarProduto(Produto *produtos, int totalProdutos);
void alterarProduto(Produto *produtos, int totalProdutos);
void excluirProduto(Produto *produtos, int *totalProdutos);
void imprimirProduto(const Produto *produto);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir produto\n");
        printf("2. Consultar produto\n");
        printf("3. Alterar produto\n");
        printf("4. Excluir produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirProduto(produtos, &totalProdutos);
                break;
            case 2:
                consultarProduto(produtos, totalProdutos);
                break;
            case 3:
                alterarProduto(produtos, totalProdutos);
                break;
            case 4:
                excluirProduto(produtos, &totalProdutos);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

void incluirProduto(Produto *produtos, int *totalProdutos) {
    if (*totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos alcançado.\n");
        return;
    }
    Produto *p = &produtos[*totalProdutos];

    printf("Digite o ID do produto: ");
    scanf("%d", &p->id);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p->nome); // Lê string com espaços
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p->quantidadeEmEstoque);
    printf("Digite o valor do produto: ");
    scanf("%lf", &p->valorDoProduto);

    (*totalProdutos)++;
    printf("Produto incluído com sucesso.\n");
}

void consultarProduto(Produto *produtos, int totalProdutos) {
    int id, encontrado = 0;
    printf("Digite o ID do produto a consultar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {
            imprimirProduto(&produtos[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}

void alterarProduto(Produto *produtos, int totalProdutos) {
    int id, encontrado = 0;
    printf("Digite o ID do produto a alterar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {
            Produto *p = &produtos[i];
            printf("Digite o novo nome do produto: ");
            scanf(" %[^\n]", p->nome);
            printf("Digite a nova quantidade em estoque: ");
            scanf("%d", &p->quantidadeEmEstoque);
            printf("Digite o novo valor do produto: ");
            scanf("%lf", &p->valorDoProduto);
            printf("Produto alterado com sucesso.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}

void excluirProduto(Produto *produtos, int *totalProdutos) {
    int id, encontrado = 0;
    printf("Digite o ID do produto a excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i].id == id) {
            for (int j = i; j < *totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1]; // Move os produtos para "fechar o buraco"
            }
            (*totalProdutos)--;
            printf("Produto excluído com sucesso.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}

void imprimirProduto(const Produto *produto) {
    printf("ID: %d\n", produto->id);
    printf("Nome: %s\n", produto->nome);
    printf("Quantidade em estoque: %d\n", produto->quantidadeEmEstoque);
    printf("Valor do produto: %.2f\n", produto->valorDoProduto);
}
