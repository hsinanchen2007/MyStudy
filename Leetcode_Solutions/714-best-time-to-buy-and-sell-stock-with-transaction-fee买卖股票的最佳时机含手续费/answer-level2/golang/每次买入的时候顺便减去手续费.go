### 解题思路
每次买入的时候顺便减去手续费

### 代码

```golang
func maxProfit(prices []int, fee int) int {
    if len(prices) < 2 {
        return 0
    }

    buy := 0
    sell := 0
    for i := 0;i < len(prices); i++ {
        if i == 0 {
            buy = -prices[0] - fee
        } else {
            newSell := max(sell, buy + prices[i])
            // 买入需要在减去手续费
            buy = max(buy, sell - prices[i] - fee)
            sell = newSell
        }
    }
    return sell
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}

```