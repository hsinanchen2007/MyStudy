```
func maxProfit(prices []int) int {
	var (
		ans      int = 0
		minprice int = 1e9
	)
	for _, v := range prices {
		ans = int(math.Max(float64(ans), float64(v-minprice)))
		minprice = int(math.Min(float64(v), float64(minprice)))
	}
	return ans
}
```
