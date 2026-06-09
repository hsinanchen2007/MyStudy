### 解题思路
此处撰写解题思路

### 代码

```golang
func maxProfit(prices []int) int {
    if len(prices) <= 1{
        return 0
    }
    lowest := prices[0]
    profit := 0
    for j:=0; j< len(prices);j++{
        if prices[j] - lowest > profit {
            profit = prices[j] - lowest
        }
        if prices[j] < lowest{
            lowest = prices[j]
        }
    }
    return profit
}
```