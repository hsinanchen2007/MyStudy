最值问题可以考虑用动态规划解决.

定义dp[i] 为踏上索引为 i 的阶梯需要的最小花费。

base case:
dp[0]:跳上索引为0的阶梯,为 cost[0]
dp[1]:跳上索引为1的阶梯,为 cost[1]

只能跳一阶或者二阶,所以状态转移方程为：
dp[i] = min(dp[i-1],dp[i-2]) + cost[i]

最后要爬到楼梯顶，可以看成是 索引为 costSize 的阶梯，不需要花费。可以从索引 costSize-1或者 costSize-2 的阶梯跳上去，所以最后的结果是dp[costSize-1]和dp[costSize-2]的最小值。

题目限定了costSize >= 2,不需要考虑边界输入.

```
int minCostClimbingStairs(int* cost, int costSize){
    int dp[costSize];
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2;i < costSize;++i)
    {
        dp[i] = fmin(dp[i-1],dp[i-2]) + cost[i];
    }
    return fmin(dp[costSize-1],dp[costSize-2]);
}
```

当然使用宏定义速度更快:

```
#define MIN(a,b) ((a)<=(b)?(a):(b))

int minCostClimbingStairs(int* cost, int costSize){
    int dp[costSize];
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2;i < costSize;++i)
    {
        dp[i] = MIN(dp[i-1],dp[i-2]) + cost[i];
    }
    return MIN(dp[costSize-1],dp[costSize-2]);
}
```

