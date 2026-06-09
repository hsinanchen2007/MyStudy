![image.png](https://pic.leetcode-cn.com/652926164ab247e3cfeb1cdc4fc93a5712878cda559ee496a5524931608d30dd-image.png)

```
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if ((arr == NULL) || (arrSize == 0)) {
        *returnSize = 0;
        return NULL;
    }
    int *returnValue = (int *)malloc(k * sizeof(int));

    memset(returnValue, 0, k * sizeof(int));
    qsort(arr, arrSize, sizeof(arr[0]), cmp);
    memcpy(returnValue, arr, k * sizeof(int));
    *returnSize = k;
    return returnValue;
}
```
