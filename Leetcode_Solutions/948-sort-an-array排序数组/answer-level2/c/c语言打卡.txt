### 解题思路
计数排序

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define SIZE 100001
 #define HASH(a) ((a) + 50000)
int* sortArray(int* nums, int numsSize, int* returnSize){
    int i, *result = (int*)calloc(numsSize, sizeof(int)), support[SIZE];
    memset(support, 0, SIZE * sizeof(int));
    for(i = 0;i < numsSize;i ++)
        support[HASH(nums[i])] ++;
    for(i = 1;i < SIZE;i ++)
        support[i] += support[i - 1];
    for(i = numsSize - 1;i >= 0;i --){
        result[support[HASH(nums[i])] - 1] = nums[i];
        support[HASH(nums[i])] --;
    }
    *returnSize = numsSize;
    return result;
}
```