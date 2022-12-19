### 解题思路
官方题解用go语言写.hold是得出买入后能得到的最大值,即:股票值的最低点.cash是当前能赚的最多钱,即每个最高点减去最低点减手续费且大于0的和.

### 代码

```golang
func maxProfit(prices []int, fee int) int {
    var cash = 0
    var hold = -prices[0]
    for i := 1; i < len(prices); i++ {
        cash = max(cash, hold + prices[i] - fee)
        hold = max(hold, cash - prices[i])
    }
    return cash
}

func max (l int, r int) int {
    if l > r {
        return l
    }else {
        return r
    }
}
```