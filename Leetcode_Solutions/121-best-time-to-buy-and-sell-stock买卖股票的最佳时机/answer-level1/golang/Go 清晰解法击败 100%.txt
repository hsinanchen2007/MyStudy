其实按题意不就是找最小的买入, 最大的卖出？说了这么多, 管什么动态规划不规划？

```go
func maxProfit(prices []int) int {
	min := int(^uint(0) >> 1) // 存最小买入
	max := 0                  // 最大利润

	for i := 0; i < len(prices); i++ {
		if prices[i] < min {
			min = prices[i] // 更新最小买入
		} else if prices[i]-min > max {
			max = prices[i] - min // 只要当前减去最小买入比最大利润大就将此利润更新为 max 利润
		}
	}
	return max
}
```
