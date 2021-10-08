#include <stdio.h>
#include<stdlib.h> //biblioteca p alocar memmorioa
#include<time.h>

int main(){
  int tamanho; //tamanho do vetor
  int i, j, aux;
  int *vetor;
  time_t tInicio, tFim;
  float tempo;
  FILE *arquivo;
  int iteracao=0, troca=0, comparacao=0;

  //abre o arquivo com os nros
  arquivo = fopen("arquivo_100.txt", "r");

  //le oo arquivo com os nros
  fscanf(arquivo, "%d", &tamanho);

  printf("BUBBLE SORT COM %d NUMEROS\n", tamanho);

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

  //BUBBLE SORT
  for(i=0;i<tamanho;i++){ //iteracao
    iteracao++;
    for(j=0;j<tamanho-1;j++){ //iteracao
      iteracao++;
      comparacao++;
      if(vetor[j]>vetor[j+1]){ //comaracao
        aux = vetor[j]; //troca
        vetor[j] = vetor[j+1];
        vetor [j+1] = aux;
        troca++;
      }
    }
  }

  //para de contar o tempo
  tFim = clock();

  tempo = (tFim - tInicio) * (1000.0 / CLOCKS_PER_SEC);

  printf("TEMPO: %.2fms\n", tempo);
  printf("ITERACOES: %d\n", iteracao);
  printf("COMPARACOES: %d\n", comparacao);
  printf("TROCAS: %d\n", troca);

  printf("VETOR ORDENADO:\n");
  arquivo = fopen("sai_bubbleSort.txt", "w");

  for(i=0; i<tamanho; i++){
    fprintf (arquivo, "%d ", vetor[i]);
    printf("[%d] %d\n", i+1, vetor[i]);
  }

  fclose(arquivo);
  free(vetor);

  return 0;
}
