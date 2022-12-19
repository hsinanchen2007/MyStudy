```
func maxProfit(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}
	p1, p2 := 0, 1
	profit := 0
	for {
		if p2 > len(prices)-1 {
			break
		}
		if prices[p1] < prices[p2] {
			if p2+1 <= len(prices)-1 {
                if  prices[p2+1] >= prices[p2] {
                    p2 = p2 + 1
                } else {
                    profit += prices[p2] - prices[p1]
				    p1, p2 = p2+1, p2+2
                }
			} else {
				profit += prices[p2] - prices[p1]
				p1, p2 = p2+1, p2+2
			}
		} else {
			p1, p2 = p2, p2+1
		}
	}
	return profit
}
```
