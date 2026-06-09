### 解题思路
自己没想出来，参考的官解方法一动态规划

### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0)
    {
        return 0;
    }
    int dp[numsSize]; //以第i个数为最后一位的最长子序列长度
    int ans=1;

    dp[0]=1;
    for(int i=1;i<numsSize;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
        {
            if(dp[i]<dp[j] && nums[i]>nums[j])
            {
                dp[i]=dp[j];
            }
        }
        dp[i]++;
        ans=ans>dp[i]?ans:dp[i];
    }
    return ans;
}
```