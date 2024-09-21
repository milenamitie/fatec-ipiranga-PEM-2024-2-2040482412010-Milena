/*-------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Carlos Veríssimo                        *                                                                   *
*--------------------------------------------------------*
* Objetivo do Programa: Atividade N_7: Bugs da HP12c     * 
* Data - 21/09/2024                                      * 
* Autor: Milena Mitie                                    *
*-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAMANHO_PILHA 4

// Função para exibir a pilha
void exibirPilha(int pilha[]) {
    printf("Pilha: [T: %d] [Z: %d] [Y: %d] [X: %d]\n",
           pilha[3], pilha[2], pilha[1], pilha[0]);
}

// Função para empurrar valores na pilha
void empurrar(int pilha[], int valor) {
    for (int i = TAMANHO_PILHA - 1; i > 0; i--) {
        pilha[i] = pilha[i - 1];
    }
    pilha[0] = valor;
}

// Função para executar a operação entre os dois primeiros operandos da pilha
int executarOperacao(int pilha[], char operador) {
    int resultado;

    // Verifica se há operandos suficientes para a operação
    if (pilha[1] == 0 && (operador == '+' || operador == '-' || operador == '*' || operador == '/')) {
        printf("Erro: Operação inválida. Não há operandos suficientes.\n");
        return -1;
    }

    // Opera entre o penúltimo (pilha[1]) e o último (pilha[0]) valor
    switch (operador) {
        case '+':
            resultado = pilha[1] + pilha[0];
            break;
        case '-':
            resultado = pilha[1] - pilha[0];
            break;
        case '*':
            resultado = pilha[1] * pilha[0];
            break;
        case '/':
            if (pilha[0] == 0) {
                printf("Erro: Divisão por zero não permitida.\n");
                return -1;
            }
            resultado = pilha[1] / pilha[0];
            break;
        default:
            printf("Erro: Operador inválido.\n");
            return -1;
    }

    // Atualiza a pilha com o resultado da operação
    pilha[0] = resultado;
    for (int i = 1; i < TAMANHO_PILHA - 1; i++) {
        pilha[i] = pilha[i + 1]; // Faz o shift nos valores para liberar espaço
    }
    pilha[TAMANHO_PILHA - 1] = 0; // Limpa o topo da pilha

    return 0; // Retorna sucesso
}

int main() {
    int pilha[TAMANHO_PILHA] = {0, 0, 0, 0}; // Inicializando a pilha com zeros
    char entrada[100]; // Para armazenar a entrada do usuário
    char continuar;

    printf("Bem-vindo à Calculadora Fatec-HP12c!\n");
    
    do {
        printf("\nDigite a expressão em formato RPN (ex: 5 1 2 + 4 * + 3) ou 'sair' para encerrar: ");
        fgets(entrada, sizeof(entrada), stdin); // Lê a entrada do usuário

        // Verificar se o usuário deseja sair
        if (strncmp(entrada, "sair", 4) == 0) {
            break;
        }

        // Dividir a entrada em tokens (números e operadores)
        char *token = strtok(entrada, " ");
        while (token != NULL) {
            // Verifica se o token é um número (operando)
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                int valor = atoi(token); // Converte o token para número inteiro
                empurrar(pilha, valor); // Empurra o número para a pilha
                exibirPilha(pilha); // Exibe o estado da pilha
            }
            // Caso contrário, trata-se de um operador
            else {
                if (executarOperacao(pilha, token[0]) == -1) {
                    // Se houver erro na operação, encerrar o loop atual
                    break;
                }
                exibirPilha(pilha); // Exibe o estado da pilha
            }
            token = strtok(NULL, " "); // Avança para o próximo token
        }

        printf("\nResultado final: %d\n", pilha[0]); // Exibe o resultado final

        // Pergunta ao usuário se deseja realizar outra operação
        printf("\nDeseja realizar outra operação? (s/n): ");
        scanf(" %c", &continuar);
        getchar(); // Limpa o buffer

    } while (continuar == 's' || continuar == 'S');

    // Mensagem de encerramento
    printf("Obrigado por usar nossa Calculadora Fatec-HP12c!\n");
    
    return 0;
}
