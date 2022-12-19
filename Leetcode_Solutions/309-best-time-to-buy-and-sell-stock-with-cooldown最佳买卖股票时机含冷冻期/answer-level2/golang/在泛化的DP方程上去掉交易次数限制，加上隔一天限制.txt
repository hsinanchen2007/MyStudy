### 解题思路
在泛化的DP方程上去掉交易次数限制，加上隔一天限制

### 代码

```golang
func maxProfit(prices []int) int {
    // 动态规划 dp[i][k][0] dp[i][k][1]分别表示第i天没有持有股票和有持有股票，k表示还可以交易的次数
    if len(prices) < 2 {
        return 0
    }

    var dp [][]int
    // dp[0][0][0] = 0, dp[0][0][1] = -prices[0]
    // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])
    // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k - 1][0]- prices[i])

    for i := 0;i < len(prices); i++ {
        var status = make([]int, 2)
        status[0] = 0
        status[1] = 0
        dp = append(dp, status)
    }

    for i := 0;i< len(prices); i++ {
            if i == 0 {
                dp[i][1] = -prices[0]
            } else if i == 1 {
                dp[i][1] = max(-prices[0], -prices[1])
                dp[i][0] = max(0, prices[1] - prices[0])
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
                // 冷冻期
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i])
            }
    }
    return dp[len(prices) - 1][0]
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}
```