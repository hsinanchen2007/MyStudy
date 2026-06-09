### 解题思路
使用qsort快速排序。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int Cmp(const void *a, const void *b) {
     return (*(int *)a - *(int *)b);
 }
int* sortArray(int* nums, int numsSize, int* returnSize){
    int i;
    int *returNums;
    returNums = (int *)malloc(sizeof(int) * (numsSize + 1));
    for (i = 0; i < numsSize; i++) {
        returNums[i] = nums[i];
    }
    qsort(returNums, numsSize, sizeof(int), Cmp);
    *returnSize = numsSize;
    return returNums;
}
```