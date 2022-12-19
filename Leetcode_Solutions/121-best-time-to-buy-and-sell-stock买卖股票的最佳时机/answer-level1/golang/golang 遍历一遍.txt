### 解题思路
一遍遍历

### 代码

```golang
func maxProfit(prices []int) int {
    if len(prices) == 0 {
		return 0
	}
	
	minPrice := [2]int{0, prices[0]}
	
	max := 0
	for i, p := range prices {
		// 找到当前小的值
		if p < minPrice[1] {
			minPrice[0] = i
			minPrice[1] = p
		}
		
		// 当前值减去最小的值，并获得最大收益
		if p - minPrice[1] > max {
			max = p - minPrice[1]
		}
		
	}
	
	return max
}
```