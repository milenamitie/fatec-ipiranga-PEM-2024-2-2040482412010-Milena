#include <stdio.h>
#include <stdlib.h>

// Função para comparar elementos para ordenação
int comparar(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
}

// Função para calcular a nota final excluindo a maior e a menor nota
float calcularNotaFinal(float notas[], int n) {
    qsort(notas, n, sizeof(float), comparar);  // Ordena as notas em ordem crescente
    float soma = 0.0;
    for (int i = 1; i < n - 1; i++) {  // Exclui a primeira (menor) e a última (maior) nota
        soma += notas[i];
    }
    return soma;
}

int main() {
    int N;
    float notaFinal = 0.0;
    int prova = 1;

    while (1) {
        // Solicitar o número de notas
        printf("Digite o número de notas (N > 2, 0 para sair): ");
        scanf("%d", &N);

        // Verificar se o usuário quer sair
        if (N == 0) {
            break;
        }

        // Verificar se N é maior que 2
        if (N <= 2) {
            printf("O número de notas deve ser maior que 2. Tente novamente.\n");
            continue;
        }

        // Criar vetor para armazenar as notas
        float notas[N];

        // Solicitar as notas
        printf("Digite as %d notas separadas por espaço: ", N);
        for (int i = 0; i < N; i++) {
            scanf("%f", &notas[i]);
        }

        // Calcular a nota final para o conjunto atual
        float notaProva = calcularNotaFinal(notas, N);
        notaFinal += notaProva;

        // Exibir a nota da prova atual
        printf("Nota da Prova %d = %.2f\n", prova, notaProva);
        prova++;
    }

    // Exibir a nota final do candidato
    printf("Nota final do candidato = %.2f\n", notaFinal);

    return 0;
}
