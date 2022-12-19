### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize){
    int *returnK = (int *)malloc(sizeof(int) * k);
    qsort(arr, arrSize, sizeof(int), cmp);
    for(int i = 0; i < k; i++) {
        returnK[i] = arr[i];
    }
    *returnSize = k;
    return returnK;
}
```