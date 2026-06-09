```
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int *mergeArray = (int *)malloc((m + n) * sizeof(int)); // 分配`(m+n)`个int空间存储排序后的数组
    int APtr = 0, BPtr = 0, mPtr = 0;

    while (APtr < m && BPtr < n) { // 将A和B进行合并排序
        if (A[APtr] < B[BPtr]) {
            mergeArray[mPtr++] = A[APtr++];
        }
        else {
            mergeArray[mPtr++] = B[BPtr++];
        }
    }

    // A或B中剩下的元素排在最后
    if (APtr < m) {
        while (APtr < m) {
            mergeArray[mPtr++] = A[APtr++];
        }
    }
    else if (BPtr < n) {
        while (BPtr < n) {
            mergeArray[mPtr++] = B[BPtr++];
        }
    }

    for (int i = 0; i < mPtr; i++) { // 将mergeArray中的元素复制到A中
        A[i] = mergeArray[i];
    }
    free(mergeArray); // 释放mergeArray的内存空间

    return A;
}
```
