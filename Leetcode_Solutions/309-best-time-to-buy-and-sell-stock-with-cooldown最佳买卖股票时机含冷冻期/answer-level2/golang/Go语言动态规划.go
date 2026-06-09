一共有3个状态: 持有股票、不持有股票+下次交易不冷冻、不持有股票+下次交易冷冻  

状态转移方程为, i表示是第几天：  
1. dp[i][持有股票] = max(dp[i-1][持有股票], dp[i-1][不持有股票+下次交易不冷冻] - prices[i])
2. dp[i][不持有股票+下次交易不冷冻] = max(dp[i-1][不持有股票+下次交易不冷冻], dp[i-1][不持有股票+下次交易冷冻])
3. dp[i][不持有股票+下次交易冷冻] = dp[i-1][持有股票、不持有股票] + prices[i]

```
func maxProfit(prices []int) int {
    if len(prices) == 0 {
        return 0
    }
	
    dp := make([][]int, 2)
    dp[0] = []int{-prices[0], 0, 0}
    dp[1] = make([]int, 3)
    
    for i := 1; i < len(prices); i++ {
        // 用长度为2的数组做状态压缩
        x, y := i%2, (i-1)%2
        // 持有股票
        dp[x][0] = maxHandler(dp[y][0], dp[y][1]-prices[i])

        // 不持有股票+下次交易不冷冻
        dp[x][1] = maxHandler(dp[y][1], dp[y][2])

        // 不持有股票+下次交易冷却
        dp[x][2] = dp[y][0] + prices[i]
    }
    // 不持有股票的时候收益更大
    return maxHandler(dp[(len(prices)-1)%2][1], dp[(len(prices)-1)%2][2])
}

func maxHandler(items ...int) int {
    max := items[0]
    for _, val := range items[1:] {
        if val > max {
            max = val
        }
    }
    return max
}

```