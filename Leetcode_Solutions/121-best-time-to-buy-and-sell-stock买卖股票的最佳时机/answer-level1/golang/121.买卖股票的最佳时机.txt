### 解题思路

简单题，看代码。

### 代码

```golang
func maxProfit(prices []int) int {
	maxprofit := 0  //最大利润
	minprice := math.MaxInt64	//最低价格
	for i:= 0;i<len(prices);i++{
		if prices[i] < minprice {  //当前价格低于最低价格，更新最低价格
			minprice = prices[i]
		}
		if prices[i]-minprice>maxprofit{	//当前利润大于最大利润，更新最大利润
			maxprofit = prices[i] - minprice
		}
	}
	return maxprofit
}
```