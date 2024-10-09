/*---------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular            *
*          Prof. Carlos Veríssimo                          *                                                                  *                                                          *
*----------------------------------------------------------*
* Objetivo do Programa: Atividade N2-2-Comparando ordenação* 
* Data - 10/10/2024                                        * 
* Autor: Milena Mitie                                      *
*---------------------------------------------------------*/


#include <stdio.h>
#include <time.h>

// Função para trocar dois valores e contar trocas
void swap(int *a, int *b, int *trocas) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*trocas)++; // Incrementa o contador de trocas
}

// Função para mostrar o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para realizar o Bubble Sort com contagem de trocas e ciclos
void bubbleSort(int arr[], int n, int *trocas, int *ciclos) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*ciclos)++; // Conta o número de ciclos
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1], trocas);
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2,
        115, 113, 118, 114, 112,
        125, 123, 128, 124, 122,
        35, 33, 38, 34, 32,
        45, 43, 48, 44, 42,
        55, 53, 58, 54, 52,
        65, 63, 68, 64, 62,
        75, 73, 78, 74, 72,
        85, 83, 88, 84, 82,
        95, 93, 98, 94, 92,
        15, 13, 18, 14, 12,
        25, 23, 28, 24, 22
    };
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int trocas = 0;
    int ciclos = 0;

    clock_t start, end;
    double cpu_time_used;

    // Inicia medição de tempo
    start = clock();

    // Executa Bubble Sort
    bubbleSort(arr, n, &trocas, &ciclos);

    // Finaliza medição de tempo
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Exibe resultados
    printf("Array ordenado: ");
    printArray(arr, n);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);
    printf("Quantidade de trocas: %d\n", trocas);
    printf("Quantidade de ciclos: %d\n", ciclos);

    return 0;
}
