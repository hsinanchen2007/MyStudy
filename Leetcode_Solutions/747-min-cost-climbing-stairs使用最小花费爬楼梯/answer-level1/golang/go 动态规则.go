go 动态规划，介绍为什么要数组末尾要补0
``` golang
func minCostClimbingStairs(cost []int) int {
    return method_dp(cost)
}
//主要点：
//1、每个使用到的台阶有花费值，因此应该把花费值算上。 
//2、最后一个台阶不一定用上，也有可以是跃过，因此把在数组末尾补0，用以把跃过最一阶的可能也算上
//dp[i] = min(dp[i-2], dp[i-1]) + cost[i]
func method_dp(cost []int) int {
    if len(cost) == 0 {
        return 0
    }
    if len(cost) == 1 {
        return cost[0]
    }

    cost = append(cost, 0)

    dp := make([]int, len(cost))
    dp[0] = cost[0]
    dp[1] = getMin(cost[0] + cost[1], cost[1])
    for i := 2; i < len(cost); i++ {
        dp[i] = getMin(dp[i-2], dp[i-1]) + cost[i]
    }
    return dp[len(cost)-1]
}

func getMin(a, b int) int {
    if a < b {
        return a
    }
    return b
}

```
