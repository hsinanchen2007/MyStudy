### 解题思路
    如果k太大可能是超慢，这时候可以与随便交易等价，利用贪心算法，只要后面的价格高就可以买卖
### 代码

```golang
func maxProfit(k int, prices []int) int {
    // 动态规划 dp[i][k][0] dp[i][k][1]分别表示第i天没有持有股票和有持有股票，k表示还可以交易的次数
    if len(prices) < 2 {
        return 0
    }
    if k < 1 {
        return 0
    }

    if k > len(prices) / 2 {
        return maxProfitGreedy(prices)
    }

    var dp [][][]int
    // dp[0][0][0] = 0, dp[0][0][1] = -prices[0]
    // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])
    // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k - 1][0]- prices[i])

    for i := 0;i < len(prices); i++ {
        var tmp [][]int
        for t := k; t >= 0; t-- {
            var status = make([]int, 2)
            status[0] = 0
            status[1] = 0
            tmp = append(tmp, status)
        }
        dp = append(dp, tmp)
    }

    for i := 0;i< len(prices); i++ {
        for t := k; t > 0; t-- {
            if i == 0 {
                dp[i][t][1] = -prices[0]
            } else {
                dp[i][t][0] = max(dp[i - 1][t][0], dp[i - 1][t][1] + prices[i])
                dp[i][t][1] = max(dp[i - 1][t][1], dp[i - 1][t - 1][0] - prices[i])
            }
        }
    }
    res := 0
    for t := k; t > 0; t--  {
        if dp[len(prices) - 1][t][0] > res {
            res = dp[len(prices) - 1][t][0]
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

func maxProfitGreedy(prices []int) int {
    res := 0
    for i := 0; i < len(prices) - 1; i++ {
        if prices[i + 1] > prices[i] {
            res = res + prices[i + 1] - prices[i]
        }
    }
    return res
}
```