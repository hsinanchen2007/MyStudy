```
#define max(a,b) (a)>(b)?(a):(b)
int maxSubArray(int* nums, int numsSize)
{
    if(nums == NULL || numsSize ==0)return 0;
    if(numsSize == 1)return nums[0];
    int dp[numsSize];
    dp[0] = nums[0];   
    int maxsum = dp[0];
    for(int i=1;i<numsSize;i++)
    {
        dp[i] = max(dp[i-1]+nums[i],nums[i]);
        maxsum = max(maxsum,dp[i]);
    }
    return maxsum;
}
```
