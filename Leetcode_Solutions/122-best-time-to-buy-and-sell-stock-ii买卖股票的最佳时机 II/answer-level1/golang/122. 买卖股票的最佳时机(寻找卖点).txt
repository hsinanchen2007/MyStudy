```
func maxProfit(prices []int) int {
    //遍历数组，考察当前元素小于后继元素，则出现卖点，并累计利润
    profit := 0 
    for k,v :=range prices {
        if k+1 < len(prices)  && v < prices[k+1]{
            profit += prices[k+1] - v
        }
    }
    return profit
}

```
