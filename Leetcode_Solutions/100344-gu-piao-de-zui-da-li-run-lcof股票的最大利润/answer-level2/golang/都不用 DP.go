```
func maxProfit(prices []int) int {
	if len(prices) == 0 {
		return 0
	}

	minPrice := prices[0]
	bestPrice := 0
	for i := 1; i < len(prices); i++ {
		if prices[i] < minPrice {
			minPrice = prices[i]
		}
		if prices[i]-minPrice > bestPrice {
			bestPrice = prices[i] - minPrice
		}
	}

	return bestPrice
}
```
