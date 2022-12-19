### 解题思路
动态规划：
        dp[i] = max(dp[i - 1],  dp[i - 2] + nums[i])

### 代码

```c
int rob(int* nums, int numsSize){
    if(numsSize < 1)
        return 0;
    if(numsSize < 2)
        return nums[0];
    int i = 0;
    int* dp = (int *)malloc(numsSize * sizeof(int));
    int tmp = 0;
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for(i = 2; i < numsSize; i++){
        tmp = dp[i - 2] + nums[i];
        dp[i] = dp[i - 1] > tmp ? dp[i - 1] : tmp;
    }
    int ret = dp[numsSize - 1];
    free(dp);
    return ret;
}
```