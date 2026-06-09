### 解题思路
排序，返回前k个即可

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    *returnSize = 0;
    if (arr == NULL) {
        return NULL;
    }

    if (arrSize <= k) {
        *returnSize = arrSize;
        return arr;
    }

    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = k;
    return arr;
}
```