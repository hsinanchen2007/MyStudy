### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int CompareByIncrease(const void *a, const void *b){
    return *(int *)a-*(int*)b;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr, arrSize, sizeof(int), CompareByIncrease);
    *returnSize=k;
    return arr;
}
```