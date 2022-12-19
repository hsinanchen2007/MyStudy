### 解题思路
核心方程 dp[i] = Max(dp[i-1]+nums[i],nums[i])

dp[i]:表示以nums[i]结尾的最大最短的子序列

这里dp的含义是关键 一直把dp[i]当成是前i个数字中的最大子序和，迟迟求不出来

试着自己把过程从头到尾撸一遍 才能搞明白dp的含义 中间是用一个临时变量存储z寻找过程中
的最大值 最后的dp[n]并不是结果

### 代码

```c
#define MAX(a,b)  ((a)>(b)?(a):(b))
int maxSubArray(int* nums, int numsSize)
{
     int *dp = (int *)malloc(sizeof(int)*numsSize);
    int temp_max;
    dp[0] = nums[0];
    temp_max = dp[0];
    for(int i=1;i<numsSize;i++)
    {
        dp[i] = MAX(dp[i-1]+nums[i],nums[i]);
        if(dp[i]>temp_max)
        {
            temp_max = dp[i];
        }
    }
    return temp_max;
}
```