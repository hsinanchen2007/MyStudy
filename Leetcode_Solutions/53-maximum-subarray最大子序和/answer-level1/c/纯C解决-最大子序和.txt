### 解题思路
此处撰写解题思路

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int dp[numsSize];//dp[i]代表以下标为i结束的最大子序列和
    int i;

    dp[0]=nums[0];//初始化
    int max=dp[0];

    for(i=1;i<numsSize;i++)
    {
        dp[i]=nums[i]>dp[i-1]+nums[i]?nums[i]:dp[i-1]+nums[i];//状态转移方程
        max=dp[i]>max?dp[i]:max;
    }
    return max;
}
```