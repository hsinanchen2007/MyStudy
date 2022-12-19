### 解题思路
需要注意k为0，或arrSize为0时，不仅要返回NULL，还需要把*returnSize赋为0。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp_func(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
} 
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(k == 0 || arrSize == 0){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = k;
    int *result = (int *)calloc(k, sizeof(int));
    qsort(arr, arrSize, sizeof(int), cmp_func);
    for(int i = 0; i < k; i++){
        result[i] = arr[i];
    }
    return result;
}
```