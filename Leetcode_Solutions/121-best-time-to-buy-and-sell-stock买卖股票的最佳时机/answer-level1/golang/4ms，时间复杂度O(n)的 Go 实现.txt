![image.png](https://pic.leetcode-cn.com/e21d9641b8b83586e8456d77889a793ba769786b95e45c8866eccf2f3de16550-image.png)

方法一：最朴素的方法，遍历所有获利，记录最大获利，时间复杂度为O(n^2)（292ms）
```
func maxProfit(prices []int) int {  // O(n^2)
    Max := 0
    for i:=0; i<len(prices)-1; i++ {
        for j:=i+1; j<len(prices); j++ {
            delta := prices[j] - prices[i]
            if delta > Max {
                Max = delta
            }
        }
    }
    return Max
}
```

方法二：遍历一遍数组，记录当前最小价格和最大获利，时间复杂度为O(n)（4ms）
```
func maxProfit(prices []int) int {  // O(n)
    if len(prices) == 0 {
        return 0
    }
    Min := prices[0]        // 记录当前股票最小价格
    Max := 0                // 记录当前最大获利
    for i:=1; i<len(prices); i++ {
        if prices[i] - Min > Max {
            Max = prices[i] - Min
        }
        if prices[i] < Min {
            Min = prices[i]
        }
    }
    return Max
}
```