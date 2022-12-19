```c
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = numsSize;
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    memcpy(ret, nums, sizeof(int) * numsSize);
    qsort(ret, numsSize, sizeof(int), cmp);
    return ret;
}
```