### 解题思路

简单的dp算法应用，mr表示买入的价格，mc表示卖出的价格，让我们买入的价格最低，卖出的价格最高这种思想去做即可。

### 代码

```golang
func maxProfit(prices []int) int {
    if prices == nil || len(prices) == 0 {
        return 0
    }
	mr, mc := -prices[0], 0
	for i := 1; i < len(prices); i++ {
		mr = max(mr, -prices[i])
		mc = max(mc, mr + prices[i])
	}
	return mc
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}


```