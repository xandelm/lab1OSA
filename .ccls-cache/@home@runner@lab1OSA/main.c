#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  MinHeap *heap = createMinHeap();
  insert(heap, "date");
  insert(heap, "banana");
  insert(heap, "elderberry");
  insert(heap, "apple");
  while (!is_empty(heap)) {
    char *min = removeMin(heap);
    printf("%s\n", min);
    free(min);
  }
}