/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Atividade N_3: Tabuleiro de Xadrez
* Data - 30/08/2024                                      * 
* Autor: Milena Mitie*
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

// Estrutura para representar uma peça de xadrez
typedef struct {
    char identificador[4];  // Ex: "BR", "BP1", "PR", etc.
    int pontos;             // Pontuação da peça
} Peca;

// Função para inicializar o tabuleiro com as peças na posição inicial e suas pontuações
void inicializarTabuleiro(Peca tabuleiro[8][8]) {
    // Preencher o tabuleiro com espaços vazios ('X' com 0 pontos)
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            strcpy(tabuleiro[i][j].identificador, "X");
            tabuleiro[i][j].pontos = 0;
        }
    }

    // Configurar peças brancas
    strcpy(tabuleiro[0][0].identificador, "BT1"); tabuleiro[0][0].pontos = 5;
    strcpy(tabuleiro[0][1].identificador, "BC1"); tabuleiro[0][1].pontos = 3;
    strcpy(tabuleiro[0][2].identificador, "BB1"); tabuleiro[0][2].pontos = 3;
    strcpy(tabuleiro[0][3].identificador, "BD");  tabuleiro[0][3].pontos = 9;
    strcpy(tabuleiro[0][4].identificador, "BR");  tabuleiro[0][4].pontos = 0;
    strcpy(tabuleiro[0][5].identificador, "BB2"); tabuleiro[0][5].pontos = 3;
    strcpy(tabuleiro[0][6].identificador, "BC2"); tabuleiro[0][6].pontos = 3;
    strcpy(tabuleiro[0][7].identificador, "BT2"); tabuleiro[0][7].pontos = 5;
    for (int i = 0; i < 8; i++) {
        sprintf(tabuleiro[1][i].identificador, "BP%d", i + 1);
        tabuleiro[1][i].pontos = 1;
    }

    // Configurar peças pretas
    for (int i = 0; i < 8; i++) {
        sprintf(tabuleiro[6][i].identificador, "PP%d", i + 1);
        tabuleiro[6][i].pontos = 1;
    }
    strcpy(tabuleiro[7][0].identificador, "PT1"); tabuleiro[7][0].pontos = 5;
    strcpy(tabuleiro[7][1].identificador, "PC1"); tabuleiro[7][1].pontos = 3;
    strcpy(tabuleiro[7][2].identificador, "PB1"); tabuleiro[7][2].pontos = 3;
    strcpy(tabuleiro[7][3].identificador, "PD");  tabuleiro[7][3].pontos = 9;
    strcpy(tabuleiro[7][4].identificador, "PR");  tabuleiro[7][4].pontos = 0;
    strcpy(tabuleiro[7][5].identificador, "PB2"); tabuleiro[7][5].pontos = 3;
    strcpy(tabuleiro[7][6].identificador, "PC2"); tabuleiro[7][6].pontos = 3;
    strcpy(tabuleiro[7][7].identificador, "PT2"); tabuleiro[7][7].pontos = 5;
}

// Função para imprimir o tabuleiro no console
void imprimirTabuleiro(Peca tabuleiro[8][8]) {
    char letrasColunas[] = "abcdefgh";

    printf("   ");  // Espaço para o índice das colunas
    for (int i = 0; i < 8; i++) {
        printf("%4c", letrasColunas[i]);  // Imprimir letras das colunas
    }
    printf("\n");

    for (int i = 0; i < 8; i++) {
        printf("%d  ", 8 - i);  // Imprimir número da linha
        for (int j = 0; j < 8; j++) {
            printf("%4s", tabuleiro[i][j].identificador);
        }
        printf("\n");
    }
}

// Função para calcular a pontuação total de cada jogador
void calcularPontuacao(Peca tabuleiro[8][8], int *pontuacaoBrancas, int *pontuacaoPretas) {
    *pontuacaoBrancas = 0;
    *pontuacaoPretas = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro[i][j].identificador[0] == 'B') {
                *pontuacaoBrancas += tabuleiro[i][j].pontos;
            } else if (tabuleiro[i][j].identificador[0] == 'P') {
                *pontuacaoPretas += tabuleiro[i][j].pontos;
            }
        }
    }
}

int main() {
    Peca tabuleiro[8][8];  // Tabuleiro 8x8 com cada posição contendo uma estrutura Peca

    inicializarTabuleiro(tabuleiro);  // Inicializa o tabuleiro com as peças nas posições iniciais
    imprimirTabuleiro(tabuleiro);     // Imprime o tabuleiro

    int pontuacaoBrancas, pontuacaoPretas;
    calcularPontuacao(tabuleiro, &pontuacaoBrancas, &pontuacaoPretas);  // Calcula as pontuações

    printf("\nPontuação Total das Brancas: %d\n", pontuacaoBrancas);
    printf("Pontuação Total das Pretas: %d\n", pontuacaoPretas);

    return 0;
}
