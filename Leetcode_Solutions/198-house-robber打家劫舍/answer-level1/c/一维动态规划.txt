

**核心方程：dp[i] =  max(dp[i-2]+nums[i],dp[i-1])**

*dp[i]表示从nums[0]到nums[i]能获得的最多钱数*



```
//C代码
int rob(int* nums, int numsSize)
{
    if(numsSize == 0)
    {
        return 0;
    }
    int *dp = (int *)malloc(numsSize*(sizeof(int)));
    dp[0]=nums[0];
    if(numsSize >= 2)
    {
        dp[1]= nums[0]>nums[1]?nums[0]:nums[1];
        for(int i=2;i<numsSize;i++)
        {
            if(nums[i]+dp[i-2]>dp[i-1])
            {
                dp[i] = dp[i-2] + nums[i];
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
    }
    return dp[numsSize -1];
    
}
```

