**设dp[i]表示第i个房屋之前的最高金额，则求dp[numsSize-1]即可。**
**状态转移方程：**
- dp[0] = nums[0]
- dp[1] = max(nums[1], nums[0])
- dp[i] = max(dp[i-2] + nums[i], dp[i-1])(i>=2)

```c
int rob(int* nums, int numsSize){
    if(!nums || numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    int *dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    dp[1] = fmax(nums[1], nums[0]);
    for(int i = 2; i < numsSize; i++){
        dp[i] = fmax(dp[i-2] + nums[i], dp[i-1]);
    }
    return dp[numsSize - 1];
}
```