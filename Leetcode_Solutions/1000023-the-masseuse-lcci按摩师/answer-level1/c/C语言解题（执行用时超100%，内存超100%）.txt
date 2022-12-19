### 解题思路
首先分析题意可知，每天只有两个状态，买与不买，分别用1和0代表当天买与不买

创建二维数组dp[numsSize][2];
每一天有两个状态：（1）如果今天不买，那么dp[i][0]就应给取前一天买或不买的最大值，即dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
               （2）如果今天要买，那么必须满足前一天不可以买的条件，即dp[i][1]=dp[i][0]+nums[i];

### 代码

```c
#define max(a,b) (a)>(b)?(a):(b)

int massage(int* nums, int numsSize)
{
    if(!numsSize)
        return 0;
    int dp[numsSize][2];
    for(int i=0;i<numsSize;i++)
        dp[i][0]=dp[i][1]=0;
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for(int i=1;i<numsSize;i++)
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0]+nums[i];
    }
    return max(dp[numsSize-1][0], dp[numsSize-1][1]);
}
```

