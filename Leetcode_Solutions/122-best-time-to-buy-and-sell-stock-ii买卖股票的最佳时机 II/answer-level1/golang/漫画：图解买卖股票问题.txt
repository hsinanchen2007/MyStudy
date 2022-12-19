本题关键之处（完整代码见文末）：

- 不能参与多笔交易
- 尽可能多地进行交易

![image.png](https://pic.leetcode-cn.com/7041f9f79033a4599ccfc9fa311f89e9a154c2850ff71eda26cc52ff8c11f17d-image.png)


```go []
func maxProfit(prices []int) int {
    if len(prices) < 2 {
        return 0
    }
    dp := make([][2]int, len(prices))
    dp[0][0] = 0
    dp[0][1] = -prices[0]
    for i := 1; i < len(prices); i++ {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i])
        dp[i][1] = max(dp[i-1][0]-prices[i],dp[i-1][1])
    }
    return dp[len(prices)-1][0]
}

func max(a,b int) int {
    if a > b {
        return a
    }
    return b
}
```
