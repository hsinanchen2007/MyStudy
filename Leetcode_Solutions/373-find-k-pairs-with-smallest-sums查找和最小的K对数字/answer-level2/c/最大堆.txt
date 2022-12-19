考虑使用最大堆求解，先把堆插满，然后判断待插入元素是否比堆顶元素大：
当堆满的时候判断待插入元素是否比堆顶元素大
1.比堆顶元素大则本次不插入
2.比堆顶元素小，先删除堆顶元素，然后插入待插入元素
注:手工写的堆，写的比较挫，将就着看吧
```
struct Heap {
    int num1;
    int num2;
};
struct HeapTable {
    struct Heap *heap;
    int curSize;
    int maxSize;
};
struct HeapTable *HeapTableCreate(int maxSize)
{
    struct HeapTable *heapTable = (struct HeapTable *)malloc(sizeof(struct HeapTable));
    if (heapTable == NULL) {
        return NULL;
    }
    heapTable->heap = (struct Heap *)malloc(sizeof(struct Heap) * maxSize);
    if (heapTable->heap == NULL) {
        free(heapTable);
        heapTable = NULL;
        return NULL;
    }
    (void)memset(heapTable->heap, 0, sizeof(struct Heap) * maxSize);
    heapTable->curSize = 0;
    heapTable->maxSize = maxSize;
    return heapTable;
}
int Comp(struct Heap x1, struct Heap x2)
{
    if (x1.num1 + x1.num2 < x2.num1 + x2.num2) {
        return 1;
    } else {
        return 0;
    }
}
void HeapTableDelete(struct HeapTable *heapTable)
{
    int i, c;
    struct Heap x;
    if (heapTable->curSize <= 0) {
        return;
    }
    x = heapTable->heap[heapTable->curSize - 1];
    heapTable->curSize = heapTable->curSize - 1;
    i = 0;
    c = 2 * i + 1;
    while (c < heapTable->curSize) {
        if (c + 1 < heapTable->curSize && Comp(heapTable->heap[c], heapTable->heap[c + 1])) {
            c++;
        }
        if ((heapTable->heap[c].num1 + heapTable->heap[c].num2) <= (x.num1 + x.num2)) {
            break;
        }
        heapTable->heap[i] = heapTable->heap[c];
        i = c;
        c = 2 * c + 1;
    }
    heapTable->heap[i] = x;
}
void HeapTableInsert(struct HeapTable *heapTable, int num1, int num2)
{
    int i;
    struct Heap y = {0};
    y.num1 = num1;
    y.num2 = num2;
    if (heapTable == NULL || heapTable->heap == NULL) {
        return;
    }
    // 当堆满的时候判断待插入元素是否比堆顶元素大
    // 1.比堆顶元素大则不插入
    // 2.比堆顶元素小，先删除堆顶元素，然后插入
    if (heapTable->curSize == heapTable->maxSize) {
        if (Comp(heapTable->heap[0], y)) {
            return;
        }
        HeapTableDelete(heapTable);
    }
    heapTable->curSize += 1;
    //c = heapTable->curSize + 1;
    i = heapTable->curSize;
    while (i > 1 && Comp(heapTable->heap[i / 2 - 1], y)) {
        heapTable->heap[i - 1] = heapTable->heap[i / 2 - 1];
        i = i / 2;
    }
    heapTable->heap[i - 1] = y;
}
void HeapTableOutput(struct HeapTable *heapTable, int **result)
{
    int i;
    if (heapTable == NULL || heapTable->heap == NULL || result == NULL) {
        return;
    }
    for (i = 0; i < heapTable->curSize; i++) {
        result[i][0] = heapTable->heap[i].num1;
        result[i][1] = heapTable->heap[i].num2;
    }
}
void HeapTableDestroy(struct HeapTable **heapTable)
{
    if (heapTable == NULL || *heapTable == NULL) {
        return;
    }
    if ((*heapTable)->heap != NULL) {
        free((*heapTable)->heap);
        (*heapTable)->heap = NULL;
    }
    free(*heapTable);
    *heapTable = NULL;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    int i, j;
    int **returnResult = NULL;
    struct HeapTable *heapTable = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (nums1Size <= 0 || nums2Size <= 0 || k <= 0) {
        return NULL;
    }

    heapTable = HeapTableCreate(k);
    if (heapTable == NULL) {
        return NULL;
    }

    if (nums1Size * nums2Size < k) {
        *returnSize = nums1Size * nums2Size;
    } else {
        *returnSize = k;
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    if (*returnColumnSizes == NULL) {
        HeapTableDestroy(&heapTable);
        return NULL;
    }
    //(void)memset(*returnColumnSizes, 0, sizeof(int));
    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    
    returnResult = (int **)malloc(sizeof(int *) * (*returnSize));
    for (i = 0; i < (*returnSize); i++) {
        returnResult[i] = (int *)malloc(sizeof(int) * 2);
        (void)memset(returnResult[i], 0, sizeof(int) * 2);
    }
    for (i = 0; i < nums1Size; i++) {
        for (j = 0; j < nums2Size; j++) {
            HeapTableInsert(heapTable, nums1[i], nums2[j]);
        }
    }
    HeapTableOutput(heapTable, returnResult);
    HeapTableDestroy(&heapTable);
    return returnResult;
}
```
