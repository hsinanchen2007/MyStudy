### 解题思路
此处撰写解题思路

### 代码

```golang
func maxProfit(prices []int) int {
    // 动态规划 dp[i][k][0] dp[i][k][1]分别表示第i天没有持有股票和有持有股票，k表示还可以交易的次数
    if len(prices) < 2 {
        return 0
    }
    K := 2
    var dp [][][]int
    // dp[0][0][0] = 0, dp[0][0][1] = -prices[0]
    // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])
    // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k - 1][0]- prices[i])

    for i := 0;i < len(prices); i++ {
        var tmp [][]int
        for k := K; k >= 0; k-- {
            var status = make([]int, 2)
            status[0] = 0
            status[1] = 0
            tmp = append(tmp, status)
        }
        dp = append(dp, tmp)
    }

    for i := 0;i< len(prices); i++ {
        for k := K; k > 0; k-- {
            if i == 0 {
                dp[i][k][1] = -prices[0]
            } else {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
            }
        }
    }
    res := 0
    for k := K; k > 0; k--  {
        if dp[len(prices) - 1][k][0] > res {
            res = dp[len(prices) - 1][k][0]
        }
    }
    return res
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}
```