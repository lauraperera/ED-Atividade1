#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int tamanho; //tamanho do vetor
    int i, filho, pai, ultimo, aux;
    int *vetor;
    time_t tInicio, tFim;
    float tempo;
    FILE *arquivo;
    int iteracao=0, troca=0, comparacao=0;

    //abre o arquivo com os nros
    arquivo = fopen("arquivo_100000.txt", "r");

    //le o arquivo com os nros
    fscanf(arquivo, "%d", &tamanho);

    printf("SELECTION SORT COM %d NUMEROS\n", tamanho);
    
    //alocando memória pro vetor
    vetor = (int *)malloc(tamanho * sizeof(int));

    for(i=0; i<tamanho; i++){
        //colocando nros do arquivo pro vetor
        fscanf(arquivo, "%d", &vetor[i]);
    }

    printf("VETOR NÃO ORDENADO:\n");
    for(i=0;i<tamanho;i++){
        printf("[%d] %d\n", i+1, vetor[i]);
    }

    //fecha o arquivo
    fclose(arquivo);

    //começa a contar o tempo
    tInicio = clock();

    //prepara o monte inicial
    for(i=1; i<=tamanho; i++){
        iteracao++;
        filho = i;
        pai = (i-1) / 2;
        while(filho>0 && vetor[filho]>vetor[pai]){
            iteracao;;
            troca++;
            aux = vetor[pai];
            vetor[pai] = vetor[filho];
            vetor[filho] = aux;
            filho = pai;
            pai = (filho-1) / 2;
        }
    }

    //HEAP SORT 
    ultimo = tamanho-1;

    while(ultimo > 0){
        iteracao++;
        troca++;
        aux = vetor[ultimo];
        vetor[ultimo] = vetor[0];
        vetor[0] = aux;
        ultimo--;
        pai = 0;
        filho = 1;

        while(filho <= ultimo && 
             (vetor[filho]>vetor[pai] || 
             (filho+1<=ultimo && vetor[filho+1]>vetor[pai]))){
                
            iteracao++;
            if(filho+1 <= ultimo && vetor[filho+1] > vetor[filho]){
                filho++;
                comparacao++;
            }
            troca++;
            aux = vetor[pai];
            vetor[pai] = vetor[filho];                vetor[filho] = aux;
            pai = filho;
            filho = 2*pai + 1;
           
        }
    }

    //para de contar o tempo
    tFim = clock();

    tempo = (tFim - tInicio) * (1000.0 / CLOCKS_PER_SEC);

    printf("TEMPO: %.2fms\n", tempo);
    printf("ITERACOES: %d\n", iteracao);
    printf("COMPARACOES: %d\n", comparacao);
    printf("TROCAS: %d\n", troca);

    printf("VETOR ORDENADO: sai_heapSort.txt\n");
    arquivo = fopen("sai_heapSort.txt", "w");

    for(i=0; i<tamanho; i++){
        fprintf (arquivo, "%d ", vetor[i]);
        //printf("[%d] %d\n", i+1, vetor[i]);
    }

    fclose(arquivo);
    free(vetor);

    return 0;

}