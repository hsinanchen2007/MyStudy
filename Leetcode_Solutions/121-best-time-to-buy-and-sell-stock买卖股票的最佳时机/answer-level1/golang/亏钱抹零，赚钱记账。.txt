### 解题思路

亏了钱就抹零抄底，赚了钱就记账。 

### 代码

```golang
func maxProfit(prices []int) int {
	maxprofit := 0
	if len(prices) > 1 {
		tmpprofit := 0
		for i:=1;i<len(prices);i++ {
			tmpprofit = tmpprofit + (prices[i]-prices[i-1])
			if tmpprofit < 0 {
				tmpprofit = 0
			} else if tmpprofit > maxprofit {
				maxprofit = tmpprofit
			}
		}
	}
	return maxprofit
}
```