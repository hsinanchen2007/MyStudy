```
 int cmp(const void *a, const void *b) {
     const int l = *(int *)a;
     const int r = *(int *)b;
     return l - r;
 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if (arr == NULL || arrSize <= 0 || k <=0) {
        *returnSize = 0;
        return NULL;
    }
    if (arrSize < k) {
        *returnSize = arrSize;
        return arr;
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = k;
    return arr;
}
```
