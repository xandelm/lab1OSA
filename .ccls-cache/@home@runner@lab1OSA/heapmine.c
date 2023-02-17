// #include <stdio.h>
// #include <string.h>

// typedef struct MinHeap MinHeap;
// struct MinHeap {
//   int *arr;
//   int size;

//   int parent(int i) { return (i - 1) / 2; }

//   int leftChild(int i) { return (2 * i + 2); }

//   int getMin(Minheap *heap) { return heap->arr[0]; }

//   MinHeap *initMinHeap() {
//     MinHeap *minheap = (MinHeap *)malloc(sizeof(MinHeap));
//     //minheap->arr = (char *)malloc(sizeof(char));
//     minheap->size = 0;
//     return minheap;
//   }

//   void freeMinHeap(MinHeap *heap) {
//     if (!heap)
//       return;
//     free(heap->arr);
//     free(heap);
//   }

//   MinHeap* insert(MinHeap *heap, char *s, int recordSize){
//     heap->size++;
//     if(heap->size!=0)
//       minheap->arr = (char*)malloc(sizeof(char)*recordSize);
    
//     strcpy(heap->arr[heap->size-1],s);
    
//   }
// };