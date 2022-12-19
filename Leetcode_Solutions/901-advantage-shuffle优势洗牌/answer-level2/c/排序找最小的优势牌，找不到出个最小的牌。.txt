```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define ISUSED -1
 int cmp(const void *a, const void *b) {
     const int l = *(int*)a;
     const int r = *(int*)b;
     return l - r;
 }
int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize){
    *returnSize = 0;
    if (ASize == 0 || BSize == 0) {
        return NULL;
    }
    *returnSize = ASize;
    int *ret = (int *)malloc(sizeof(int) * (*returnSize));
    memset(ret, 0, (*returnSize));
    qsort(A, ASize, sizeof(int), cmp);
    int usedIndex = 0;
    for (int i = 0; i < BSize; i++) {
        bool isFind = false;
        for (int j = 0; j < ASize; j++) {
            if (A[j] != ISUSED && B[i] < A[j]) {
                ret[i] = A[j];
                A[j] = ISUSED;
                isFind = true;
                break;
            }
        }
        if (!isFind) {
            for (int j = usedIndex; j < ASize; j++) {
                if (A[j] != ISUSED) {
                    ret[i] = A[j];
                    A[j] = ISUSED;
                    usedIndex++;
                    break;
                }
            }
        }
    }
    return ret;
}
```
