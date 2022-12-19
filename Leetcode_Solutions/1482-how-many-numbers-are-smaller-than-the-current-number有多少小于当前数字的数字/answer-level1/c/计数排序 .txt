### 解题思路
1.基于数值范围0-100，可以采用计数排序
2.count存储每个数值的计数
3.计算时将小于当前数值的计数累加起来即可。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX_NUM 101

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int count[MAX_NUM] = { 0 };
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    if (ans == NULL) {
        return NULL;
    }
    for (int i = 0; i < numsSize; i++) {
        int littleCount = 0;
        for (int j = 0; j < nums[i]; j++) {
            littleCount += count[j];
        }
        ans[i] = littleCount;
    }
    *returnSize = numsSize;
    return ans;
}
```