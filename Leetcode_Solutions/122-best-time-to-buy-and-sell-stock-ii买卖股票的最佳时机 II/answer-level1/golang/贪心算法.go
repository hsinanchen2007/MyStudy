
贪心算法能解决的问题不多，这个题是一个例子。因为局部的贪心不会带来负面效果，所以构成了全局的最优解。
```go
func maxProfit(prices []int) int {
    var sum int    
    for i :=0;i<len(prices)-1; i++ {
        if prices[i+1] > prices[i]{
            sum += prices[i+1] - prices[i]
        }
    }
    return sum
}
```
