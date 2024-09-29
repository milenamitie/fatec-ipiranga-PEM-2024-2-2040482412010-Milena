/*-------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Carlos Veríssimo                        *                                                                  *
*--------------------------------------------------------*
* Objetivo do Programa: Atividade N2-1-Bubble Sort       * 
* Data - 27/09/2024                                      * 
* Autor: Milena Mitie                                    *
*-------------------------------------------------------*/

#include <stdio.h>

// Função para trocar dois valores
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para mostrar o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para realizar o Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    
    // Entrada de dados
    printf("Digite o número de elementos: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Preenchimento do array
    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Exibe o array original
    printf("Array original: ");
    printArray(arr, n);
    
    // Classificação usando Bubble Sort
    bubbleSort(arr, n);
    
    // Exibe o array ordenado
    printf("Array ordenado: ");
    printArray(arr, n);
    
    return 0;
}
