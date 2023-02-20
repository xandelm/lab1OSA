#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  FILE *arq1pointer, *arq2pointer, *arqSaida;
  long long int campo1;
  char *tempString1, *tempString2;
  char *nomeArqSaida;
  arq1pointer = fopen(argv[1], "rb");
  arq2pointer = fopen(argv[2], "rb");
  nomeArqSaida = strcat(argv[1], ".merge");
  arqSaida = fopen(nomeArqSaida, "wb");
  if (arq1pointer == NULL || arq2pointer == NULL || arqSaida == NULL) {
    printf("Algum arquivo não abriu\n");
    exit(1);
  }
  MinHeap *heapArq = createMinHeap();
  while (fread(&campo1, sizeof(long long int), 1, arq1pointer)) {
    tempString1 = (char *)malloc(sizeof(char) * (campo1 + 1));
    fread(tempString1, sizeof(char), campo1, arq1pointer);
    tempString1[campo1] = '\0';
    insert(heapArq, tempString1);
    free(tempString1);
  }

  while (fread(&campo1, sizeof(long long int), 1, arq2pointer)) {
    tempString2 = (char *)malloc(sizeof(char) * (campo1 + 1));
    fread(tempString2, sizeof(char), campo1, arq2pointer);
    tempString2[campo1] = '\0';
    insert(heapArq, tempString2);
    free(tempString2);
  }
  while (!is_empty(heapArq)) {
    char *min = removeMin(heapArq);
    fwrite(min, sizeof(char), strlen(min), arqSaida);
    fwrite("\n", sizeof(char), 1, arqSaida);
    printf("%s\n", min);
    free(min);
  }
  destroyHeap(heapArq);
  fclose(arq1pointer);
  fclose(arq2pointer);
  fclose(arqSaida);
  return 0;
}