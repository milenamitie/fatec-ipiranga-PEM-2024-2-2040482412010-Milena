/*---------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular            *
*          Prof. Carlos Veríssimo                          *                                             *                                                          *
*----------------------------------------------------------*
* Objetivo do Programa: Atividade N2-3-Quicksort           * 
* Data - 18/10/2024                                        * 
* Autor: Milena Mitie                                      *
*---------------------------------------------------------*/


#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int low, int high) {
    int pivo = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = particionar(arr, low, high);

        quicksort(arr, low, pi - 1);  // Sublista de elementos menores que o pivô
        quicksort(arr, pi + 1, high); // Sublista de elementos maiores que o pivô
    }
}

void exibirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    exibirArray(arr, tamanho);

    quicksort(arr, 0, tamanho - 1);

    printf("Array ordenado: \n");
    exibirArray(arr, tamanho);

    return 0;
}
