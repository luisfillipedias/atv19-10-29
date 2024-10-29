#include <stdio.h>
#include <stdlib.h>

int partition(int vetor[], int esquerda, int direita, int pivô) {
    int i;
    for (i = esquerda; i < direita; i++) {
        if (vetor[i] < pivô) {
            int temp = vetor[i];
            vetor[i] = vetor[esquerda];
            vetor[esquerda] = temp;
            esquerda++;
        }
    }
    vetor[direita] = vetor[esquerda];
    vetor[esquerda] = pivô;
    return esquerda;
}

// Função para encontrar o k-ésimo menor elemento
int encontrar_k_esimo_menor(int vetor[], int tamanho_vetor, int k) {
    int esquerda = 0;
    int direita = tamanho_vetor - 1;

    while (esquerda <= direita) {
        int pivô = vetor[direita];
        int pos = partition(vetor, esquerda, direita, pivô);
        
        if (pos == k - 1) {
            return vetor[pos];
        } else if (pos < k - 1) {
            esquerda = pos + 1;
        } else {
            direita = pos - 1;
        }
    }
    return -1; 
}

int main() {
    int vetor[] = {5, 1, 9, 2, 6, 3};
    int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);
    int k = 4;

    int k_esimo_menor = encontrar_k_esimo_menor(vetor, tamanho_vetor, k);
    printf("O %d-esimo menor valor do vetor é: %d\n", k, k_esimo_menor);

    return 0;
}
