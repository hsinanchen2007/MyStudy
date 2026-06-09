记录直到当前的最小买入价格
```
func maxProfit(prices []int) int {
    if len(prices) <= 1 {
        return 0
    }
    max := 0
    buy := prices[0]
    for i := 1; i < len(prices); i++ {
        if prices[i] > buy && prices[i] - buy > max {
            max = prices[i] - buy
        }
        if prices[i] < buy {
            buy = prices[i]
        }
    }
    return max
}
```
