因为可以操作无数次，操作之后只要是赚的，就可以，因此可以使用贪心算法
```
func maxProfit(prices []int) int {
    mp := 0
    for i := 0; i < len(prices)-1; i++ {
        if prices[i+1] > prices[i] {
            mp = mp + prices[i+1] - prices[i]
        }
    }

    return mp
}

```
