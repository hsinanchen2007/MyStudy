### 解题思路
此处撰写解题思路
for i:=1;i<len(prices);i++ {
		//卖出必须要用上一次买入股票剩下的现金+本次的收益
		cash = append(cash,max(cash[i-1],buy[i-1]+prices[i]))  //卖出必然增加
		//买入必须要用上一次卖出股票剩下的现金-本次买入股票的本金
		buy  = append(buy,max(buy[i-1],cash[i-1]-prices[i])) //买入股票现金必然减少
	}
就是这个自己体会吧， 写的挺详细的了

### 代码

```golang
func maxProfit(prices []int) int {
     if len(prices) < 2 {
		return  0
	}

	cash := []int{}   //卖出股票之后剩余的现金
	buy := []int{}  //买入股票之后剩余的现金
	cash = append(cash,0)
	buy  = append(buy,-prices[0])
	for i:=1;i<len(prices);i++ {
		//卖出必须要用上一次买入股票剩下的现金+本次的收益
		cash = append(cash,max(cash[i-1],buy[i-1]+prices[i]))  //卖出必然增加
		//买入必须要用上一次卖出股票剩下的现金-本次买入股票的本金
		buy  = append(buy,max(buy[i-1],cash[i-1]-prices[i])) //买入股票现金必然减少
	}
	return cash[len(prices)-1]
}


func max(x,y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}
```