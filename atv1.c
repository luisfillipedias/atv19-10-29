#include <stdlib.h>
// Função para mesclar dois subvetores
void merge(int vetor[], int esquerda, int meio, int direita)
{
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    // Vetores temporários
    int l[n1], r[n2];
    // Copia os dados para os vetores temporários l[] e r[]
    for (i = 0; i < n1; i++)
        l[i] = vetor[esquerda + i];
    for (j = 0; j < n2; j++)
        r[j] = vetor[meio + 1 + j];
    // Mescla os vetores temporários de volta ao vetor original
    i = 0;        // Índice inicial do primeiro subvetor (l)
    j = 0;        // Índice inicial do segundo subvetor (r)
    k = esquerda; // Índice inicial do vetor mesclado
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            vetor[k] = l[i];
            i++;
        }
        else
        {
            vetor[k] = r[j];
            j++;
        }
        k++;
    }
    // Copia os elementos restantes de l[], se houver
    while (i < n1)
    {
        vetor[k] = l[i];
        i++;
        k++;
    }
    // Copia os elementos restantes de r[], se houver
    while (j < n2)
    {
        vetor[k] = r[j];
        j++;
        k++;
    }
}
// Função recursiva do merge sort
void merge_sort(int vetor[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        // Ordena a primeira e a segunda metade
        merge_sort(vetor, esquerda, meio);             // função recursiva
        merge_sort(vetor, meio + 1, direita); // função recursiva
        // Mescla as duas metades ordenadas
        merge(vetor, esquerda, meio, direita);
    }
}
// Função para imprimir o vetor
void imprimir_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}
int main()
{
    int vetor[] = {7, 4, -4, 12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    printf("Vetor original: \n");
    imprimir_vetor(vetor, tamanho);
    // Chama o merge sort
    merge_sort(vetor, 0, tamanho - 1);
    printf("Vetor ordenado: \n");
    imprimir_vetor(vetor, tamanho);
    return 0;
}