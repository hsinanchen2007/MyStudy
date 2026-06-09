### 解题思路
此处撰写解题思路
纯暴力
推荐使用单调队列

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int maxInk(int *nums, int k){
    int max = nums[0];
    for (int i = 0; i < k; i++){
        max = max > nums[i] ? max : nums[i]; 
    }
    return max;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if (!nums || numsSize < 1 || k < 0) {
        *returnSize = 0;
        return NULL;
    }
    if (k == 0) {
        return nums;
    }
    int *res = (int *)malloc(sizeof(int) * numsSize);
    memset(res, 0, sizeof(int) *numsSize);
    *returnSize = numsSize - k + 1;
    for (int i = 0; i <= numsSize - k; i++) {
        res[i] = maxInk(nums + i, k);
    }
    return res;
}
```