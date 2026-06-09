### 解题思路
贪心算法，只要后一天的价格比今天大就买入

### 代码

```golang
// 贪心算法
func maxProfit(prices []int) int {
    l := len(prices)
    if l < 2 {
        return 0
    }
    profit := 0
    for i := 0; i < l - 1; i++ {
        if prices[i + 1] > prices[i] {
            profit += prices[i + 1] - prices[i]
        }
    }
    return profit
}
```