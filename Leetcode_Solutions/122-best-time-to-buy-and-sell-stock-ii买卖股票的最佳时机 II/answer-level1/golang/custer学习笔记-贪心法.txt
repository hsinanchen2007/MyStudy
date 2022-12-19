贪心算法-只要后一天价格比前一天高，就在前一天买进后一天卖出O(n)

```go
func maxProfit(prices []int) int {
	var max int
	for i := 0; i < len(prices)-1; i++ {
		if prices[i+1] > prices[i] {
			max += prices[i+1] - prices[i]
		}
	}
	return max
}
```
