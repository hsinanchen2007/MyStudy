```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b){
    return (*(int*)a & 1) - (*(int*)b & 1);
}
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    qsort(A, ASize, sizeof(int), cmp);
    return A;
}
```