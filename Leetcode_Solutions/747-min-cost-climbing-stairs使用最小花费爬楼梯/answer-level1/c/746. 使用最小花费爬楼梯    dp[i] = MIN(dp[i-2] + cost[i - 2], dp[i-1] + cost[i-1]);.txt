### 解题思路
数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。

每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。

您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。

示例 1:

输入: cost = [10, 15, 20]
输出: 15
解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。


### 代码

```c
#define MIN(a,b) ((a)<(b)?(a):(b))
int minCostClimbingStairs(int* cost, int costSize){
    int* dp = malloc((costSize+1) * sizeof(int)), i;

    dp[0] = dp[1] =0;
    for (i = 2; i <= costSize; i++)
        dp[i] = MIN(dp[i-2] + cost[i - 2], dp[i-1] + cost[i-1]);

    return dp[costSize];
}
```