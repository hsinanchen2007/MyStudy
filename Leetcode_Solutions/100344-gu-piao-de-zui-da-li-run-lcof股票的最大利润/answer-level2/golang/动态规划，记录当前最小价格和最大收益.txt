### 解题思路
动态规划，记录当前最小价格和最大收益

### 代码

```golang
func maxProfit(prices []int) int {
    l := len(prices)
    if l == 0 {
        return 0
    }
    // 目前最大收益
    profilt := 0
    // 目前最小买入价格
    min := prices[0]
    for i := 1; i < l; i++ {
        if prices[i] <= min {
            min = prices[i]
        } else {
            tmp := prices[i] - min
            if tmp > profilt {
                profilt = tmp
            }
        }
    }
    return profilt
}
```