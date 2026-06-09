### 解题思路
dp[i]表示0到i的数据能得到的最大值，初始化dp[0]=a[0],dp[1]=max(dp[0],dp[1])
从dp[2]开始，dp[i]=max((dp[i-2]+a[i]),dp[i-1])

### 代码

```c
int massage(int* nums, int numsSize){
    if(numsSize==1)
    {
        return *(nums);
    }
    if(numsSize==0)
    {
        return 0;
    }
    int dp[numsSize];
    dp[0]=*(nums);
    dp[1]=*(nums)>*(nums+1)?*(nums):*(nums+1);
    for(int i=2;i<numsSize;i++)
    {
        dp[i]=(dp[i-2]+nums[i])>dp[i-1]?(dp[i-2]+nums[i]):dp[i-1];
    }
    return dp[numsSize-1];
}
```