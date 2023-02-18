#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  FILE *arq1pointer, *arq2pointer, *arqSaida;
  long long int campo1;
  // MinHeap *heap = createMinHeap();
  char *tempString1, *tempString2;
  arq1pointer = fopen(argv[1], "r");
  arq2pointer = fopen(argv[2], "r");
  if (arq1pointer == NULL || arq2pointer == NULL) {
    printf("Arquivo não abriu\n");
    exit(1);
  }
  MinHeap *heapArq = createMinHeap();
  MinHeap *heapArq2 = createMinHeap();
  while (fread(&campo1, sizeof(long long int), 1, arq1pointer)) {
    tempString1 = (char *)malloc(sizeof(char) *
    (campo1 + 1)); // TODO check if +1 is correct
    fread(tempString1, sizeof(char), campo1, arq1pointer);
    tempString1[campo1] = '\0';
    insert(heapArq, tempString1);
  }

  while (fread(&campo1, sizeof(long long int), 1, arq2pointer)) {
    tempString2 = (char *)malloc(sizeof(char) *
                                 (campo1 + 1)); // TODO check if +1 is correct
    fread(tempString2, sizeof(char), campo1, arq2pointer);
    tempString2[campo1] = '\0';
    insert(heapArq, tempString2);
  }
  while (!is_empty(heapArq)) {
    char *min = removeMin(heapArq);
    printf("%s\n", min);
    free(min);
  }

  return 0;
}