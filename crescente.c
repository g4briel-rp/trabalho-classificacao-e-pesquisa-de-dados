#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 95000

void bubbleSort(int array[], int length){
    int i, j;
    for(i = length - 1; i >= 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void selection_sort(int num[], int tam){
    int i, j, min, aux;
    for (i = 0; i < (tam-1); i++)
    {
        min = i;
        for (j = (i+1); j < tam; j++)
        {
            if(num[j] < num[min])
                min = j;
        }
            if (i != min)
            {
                aux = num[i];
                num[i] = num[min];
                num[min] = aux;
            }
    }
}

void insertion_sort(int vetor[], int tam){
    int temp, j;

    for(int i = 1; i < tam; i++)
    {
        temp = vetor[i];
        j = i - 1;
        while(j >= 0 && temp < vetor[j])
        {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = temp;
    }
}

void quicksort(int values[], int began, int end){
    int i, j, pivo, aux;
    i = began;
    j = end-1;
    pivo = values[began];

    while(i <= j){
        while(values[i] < pivo && i < end)
            i++;
        while(values[j] > pivo && j > began)
            j--;

        if(i <= j){
            aux = values[i];
            values[i] = values[j];
            values[j] = aux;
            i++;
            j--;
        }
    }
    if(j > began)
        quicksort(values, began, j+1);
    if(i < end)
        quicksort(values, i, end);
}

void merge(int vetor[], int comeco, int meio, int fim){
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim)
    {
        if(vetor[com1] < vetor[com2])
        {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else
        {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio)   //Caso ainda haja elementos na primeira metade
    {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim)     //Caso ainda haja elementos na segunda metade
    {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++)     //Move os elementos de volta para o vetor original
    {
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim)
    {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void criaHeap(int *vet, int i, int f){
    int aux = vet[i];
    int j = i*2+1;
    while(j <= f){
        if(j < f){
            if(vet[j] < vet[j+1]){
                j = j + 1;
            }
        }

        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2*i+1;
        }else{
            j = f+1;
        }
    }

    vet[i] = aux;
}

void heapsort(int *vet, int n){
    int i, aux;
    for(i = (n-1)/2; i >= 0; i--){
        criaHeap(vet, i, n-1);
    }

    for(i = n-1; i >= 1; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i-1);
    }
}

void imprime(int vetor[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d | ",vetor[i]);
    }

    printf("\n\n");
}

int main(){
    int quick[tamanho], bubble[tamanho], insertion[tamanho], selection[tamanho], merge[tamanho], heap[tamanho];

    double inicio, fim, diff;

    for(int i = 0; i < tamanho; i++){
        quick[i] = i+1;
        bubble[i] = i+1;
        insertion[i] = i+1;
        selection[i] = i+1;
        merge[i] = i+1;
        heap[i] = i+1;
    }

    //ORDENANDO VETOR CRESCENTE COM BUBBLE

    printf("ORDENANDO O VETOR CRESCENTE COM BUBBLE\n");

    inicio = (double) clock() / CLOCKS_PER_SEC;

    bubbleSort(bubble, tamanho);

    fim = (double) clock() / CLOCKS_PER_SEC;

    diff = fim - inicio;

    printf("tempo de execucao: %f em seg", diff);

    printf("\n\n");

    //ORDENANDO VETOR CRESCENTE COM INSERTION

    printf("ORDENANDO O VETOR CRESCENTE COM INSERTION\n");

    inicio = (double) clock() / CLOCKS_PER_SEC;

    insertion_sort(insertion, tamanho);

    fim = (double) clock() / CLOCKS_PER_SEC;

    diff = fim - inicio;

    printf("tempo de execucao: %f em seg", diff);

    printf("\n\n");

    //ORDENANDO VETOR CRESCENTE COM SELECTION

    printf("ORDENANDO O VETOR CRESCENTE COM SELECTION\n");

    inicio = (double) clock() / CLOCKS_PER_SEC;

    selection_sort(selection, tamanho);

    fim = (double) clock() / CLOCKS_PER_SEC;

    diff = fim - inicio;

    printf("tempo de execucao: %f em seg", diff);

    printf("\n\n");

    //ORDENANDO VETOR CRESCENTE COM QUICK

    printf("ORDENANDO O VETOR CRESCENTE COM QUICK\n");

    inicio = (double) clock() / CLOCKS_PER_SEC;

    quicksort(quick, 0, tamanho);

    fim = (double) clock() / CLOCKS_PER_SEC;

    diff = fim - inicio;

    printf("tempo de execucao: %f em seg", diff);

    printf("\n\n");

    //ORDENANDO VETOR CRESCENTE COM MERGE

    printf("ORDENANDO O VETOR CRESCENTE COM MERGE\n");

    inicio = (double) clock() / CLOCKS_PER_SEC;

    mergeSort(merge, 0, tamanho);

    fim = (double) clock() / CLOCKS_PER_SEC;

    diff = fim - inicio;

    printf("tempo de execucao: %f em seg", diff);

    printf("\n\n");

    //ORDENANDO VETOR CRESCENTE COM HEAP

    printf("ORDENANDO O VETOR CRESCENTE COM HEAP\n");

    inicio = (double) clock() / CLOCKS_PER_SEC;

    heapsort(heap, tamanho);

    fim = (double) clock() / CLOCKS_PER_SEC;

    diff = fim - inicio;

    printf("tempo de execucao: %f em seg", diff);

    printf("\n\n");

    return 0;
}
