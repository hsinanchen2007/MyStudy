# 排序+双指针

```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *p1, const void *p2) {
    const int a = *(int *)p1;
    const int b = *(int *)p2;
    return a > b ? 1 : -1;
}
int** pairSums(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (nums == NULL || numsSize < 2) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int **result = (int **)malloc(numsSize / 2 * sizeof(int *));
    int *columnSizes = (int *)malloc(numsSize / 2 * sizeof(int));
    int i = 0;
    int j = numsSize - 1;
    while (i < j) {
        if (nums[i] + nums[j] == target) {
            columnSizes[*returnSize] = 2;
            result[*returnSize] = (int *)malloc(columnSizes[*returnSize] * sizeof(int));
            result[*returnSize][0] = nums[i++];
            result[*returnSize][1] = nums[j--];
            *returnSize +=1;
        }else if (nums[i] + nums[j] < target) {
            i++;
        }else {
            j--;
        }
    }
    *returnColumnSizes = columnSizes;
    return result;
}
```
