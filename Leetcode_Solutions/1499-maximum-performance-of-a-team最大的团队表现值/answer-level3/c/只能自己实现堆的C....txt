```
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct tagSortArr {
    int speed;
    int efficiency;
}SortArr;

typedef SortArr VALTYPE;
typedef struct tagHeap {
    int cnt;
    VALTYPE *data;
}Heap;

int cmp(const void *a, const void *b) {
    return ((SortArr *)b)->efficiency - ((SortArr *)a)->efficiency;
}

int heapGetMin(Heap *heap, int i, int j) {
    if (i >= heap->cnt && j >= heap->cnt) {
        return 0;
    } else if (i >= heap->cnt || j >= heap->cnt) {
        return i >= heap->cnt ? j : i;
    }
    return heap->data[i].speed < heap->data[j].speed ? i : j;
}

void arrSwap(VALTYPE *array, int i, int j) {
    VALTYPE tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    return;
}

void heapTop2Down(Heap *heap, int index) {
    int lChild = 2 * index + 1;
    int rChild = 2 * index + 2;
    while (lChild < heap->cnt || rChild < heap->cnt) {
        int min = heapGetMin(heap, lChild, rChild);
        if (heap->data[min].speed > heap->data[index].speed) return;
        arrSwap(heap->data, min, index);
        index = min;
        lChild = 2 * min + 1;
        rChild = 2 * min + 2;
    }
    return;
}

void heapDown2Top(Heap *heap, int index) {
    int father = (index - 1) / 2;
    while (father >= 0 && heap->data[father].speed > heap->data[index].speed) {
        arrSwap(heap->data, father, index);
        index = father;
        father = (index - 1) / 2;
    }
    return;
}

int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k){
    SortArr *sortArr = (SortArr *)malloc(sizeof(SortArr) * n);
    for (int i = 0; i < n; i++) {
        sortArr[i].speed = speed[i];
        sortArr[i].efficiency = efficiency[i];
    }
    qsort(sortArr, n, sizeof(SortArr), cmp);

    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->data = (VALTYPE *)malloc(sizeof(VALTYPE) * (n + 1));
    heap->cnt = 0;
    long long res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (heap->cnt >= k && sortArr[i].speed > heap->data[0].speed) {
            sum += sortArr[i].speed - heap->data[0].speed ;
            heap->data[0]= sortArr[i];
            heapTop2Down(heap, 0);
            res = MAX(res, sum * sortArr[i].efficiency);
        } else if (heap->cnt < k) {
            heap->data[heap->cnt] = sortArr[i];
            heapDown2Top(heap, heap->cnt);
            heap->cnt++;
            sum += sortArr[i].speed;
            res = MAX(res, sum * sortArr[i].efficiency);
        }
    }
    free(heap->data);
    free(heap);
    return res % 100000007;
}
```
