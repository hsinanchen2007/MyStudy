### 解题思路
此处撰写解题思路
  排序后即可
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* 升序排列 */
int CmpFunc (const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
    if (arr == NULL || arrSize == 0) {
        return NULL;
    }

    qsort(arr, arrSize, sizeof(int), CmpFunc);

    int* result = (int *)malloc(arrSize * sizeof(int));
    memset(result, 0, arrSize * sizeof(int));

    int i = 0;
    for (i = 0; i < k; i++) {
        result[i] = arr[i];
    }

    *returnSize = i;
    return result;
}
```