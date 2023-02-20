#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
O Min Heap é uma árvore binária na qual o seu elemento raiz é o menor, e ela é
representada por um array. Nesse caso, como estamos usando strings como dados, o
menor se refere a comparação lexicográfica feita por strcmp()
*/
typedef struct MinHeap {
  char **arrayStrings;
  int size;
  int capacity;
} MinHeap;

/* inicializa um novo heap */
MinHeap *createMinHeap() {
  MinHeap *newHeap = (MinHeap *)malloc(sizeof(MinHeap));
  newHeap->arrayStrings = (char **)malloc(sizeof(char *));
  newHeap->size = 0;
  newHeap->capacity = 1;
  return newHeap;
}

/* troca dois elementos dentro do heap, o atual com seu filho. não mantém
 propriedade do heap. */
void swap(MinHeap *heap, int i, int j) {
  char *temp = heap->arrayStrings[i];
  heap->arrayStrings[i] = heap->arrayStrings[j];
  heap->arrayStrings[j] = temp;
}

/* insere novo elemento no heap */
void insert(MinHeap *heap, char *data) {
  /* se o heap está cheio, dobra a capacidade */
  if (heap->size == heap->capacity) {
    heap->capacity *= 2;
    heap->arrayStrings =
        (char **)realloc(heap->arrayStrings, sizeof(char *) * heap->capacity);
  }
  /* insere o novo elemento no fim do array */
  heap->arrayStrings[heap->size] = (char *)malloc(strlen(data) + 1);
  strcpy(heap->arrayStrings[heap->size], data);
  heap->size++;
  /* restora a propriedade heap comparando com os nos pais */
  int current = heap->size - 1;
  int parent = (current - 1) / 2;
  while (current > 0 &&
         strcmp(heap->arrayStrings[current], heap->arrayStrings[parent]) < 0) {
    /* enquanto o elemento atual não é raiz e o elemento atual é "menor" que o
     elemento pai(em outras palavras, não está ordenado ou na posição correta)
   */
    swap(heap, current, parent);
    current =
        parent; /* atualiza o indice do elemento atual que flutuou para cima */
    parent = (current - 1) / 2; /* atualiza o indice do novo elemento pai */
  }
}
/* remove o menor elemento do heap. o caller da função é responsável por liberar
 a memória de min */
char *removeMin(MinHeap *heap) {
  if (heap->size == 0)
    return NULL;
  char *min = heap->arrayStrings[0]; /*lembrar de liberar essa memória */
  heap->arrayStrings[0] = heap->arrayStrings[heap->size - 1];
  heap->size--;
  int current = 0;
  int left = 1;
  int right = 2;
  while (left < heap->size) {
    int child = left;
    if (right < heap->size &&
        strcmp(heap->arrayStrings[right], heap->arrayStrings[left]) < 0) {
      /* se o filho da direita do no atual existe e se o filho da direita é
      menor que filho da esquerda*/
      child = right; /* o filho da direita é menor e deve ser comparado com o
                        atual*/
      /* selecionando o menor filho, o atual sera comparado com o menor valor,
      garantindo a propriedade do min-heap */
    }
    if (strcmp(heap->arrayStrings[current], heap->arrayStrings[child]) > 0) {
      /* se o elemento atual for maior que seu menor filho*/
      swap(heap, current, child);
      current = child; /* atualiza os indices*/
      left = 2 * current + 1;
      right = 2 * current + 2;
    } else
      break;
  }
  return min;
}

/* libera memoria do heap*/
void destroyHeap(MinHeap *heap) {
  int i;
  for (i = 0; i < heap->size; i++) {
    free(heap->arrayStrings[i]);
  }
  free(heap->arrayStrings);
  free(heap);
}

int is_empty(MinHeap *heap) {
  if (heap == NULL || heap->size == 0) {
    return 1;
  }
  return 0;
}
