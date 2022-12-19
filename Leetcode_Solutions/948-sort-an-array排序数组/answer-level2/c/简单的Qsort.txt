### 解题思路
拷贝+qsort排序

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    memcpy(ret, nums, sizeof(int) * numsSize);

    qsort(ret, numsSize, sizeof(int),compare);

    return ret;
}
```