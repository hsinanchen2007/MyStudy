```
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if ((arr == NULL) || (arrSize == 0) || (k == 0)) {
        *returnSize = 0;
        return NULL;
    }
    
    qsort(arr, arrSize, sizeof(arr[0]), cmp);
    int *returnValue = (int *)malloc(k * sizeof(int));
    int i;
    *returnSize = k;
    for (i = 0; i < k; i++) {
        returnValue[i] = arr[i];
    }
    return returnValue;
}
```
