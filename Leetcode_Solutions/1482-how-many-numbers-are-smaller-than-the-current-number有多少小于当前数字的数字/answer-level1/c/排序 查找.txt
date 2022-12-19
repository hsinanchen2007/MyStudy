### 解题思路
此处撰写解题思路

### 代码

```c

int MyComp(const void *a, const void *b)
{
    return *(int*)a - *(int *)b;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * numsSize);

    memcpy(res, nums, sizeof(int) * numsSize);

    // 先排序
    qsort(nums, numsSize, sizeof(int), MyComp);

    // 再次二分查找左边界，左边界的index+1就是小于这个数的数量
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == res[i]) {
                res[i] = j;
                break;
            }
        }
    }

    *returnSize = numsSize;

    return res;
}
```