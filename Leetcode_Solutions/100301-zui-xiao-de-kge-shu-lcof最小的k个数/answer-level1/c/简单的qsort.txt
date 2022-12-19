### 解题思路
排序，返回前几个值

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int compare(const void *a, const void *b) {
     return *(int *)a - *(int *)b;
 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int *ret = (int *)malloc(sizeof(int) * k);
    qsort(arr, arrSize, sizeof(int), compare);
    *returnSize = k;
    if (k > arrSize)
        *returnSize = arrSize;
    memcpy(ret, arr,sizeof(int) * k);
    return ret;
}
```