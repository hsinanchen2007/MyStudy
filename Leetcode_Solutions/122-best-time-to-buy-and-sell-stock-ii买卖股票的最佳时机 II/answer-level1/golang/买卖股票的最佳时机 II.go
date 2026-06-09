## 结果

![image.png](https://pic.leetcode-cn.com/689650065b95cc0b85c98817ed1ff6d38cc47843cd2ad421acecb649f67148eb-image.png)

## 思路

简单遍历，在价格最低点买入，对高点卖出

```
func maxProfit(prices []int) int {
    earn := 0
    // 是否已经持有
    buy := false
    n := len(prices)
    // 买入时的价格
    var start int
    for i:=0;i<n;i++ {
        if !buy && i < n-1 && prices[i+1] < prices[i] {
            continue
        }
        if !buy {
            buy = true
            start = prices[i]
            continue
        }
        if buy && ((i < n-1 && prices[i+1] < prices[i]) || (i == n-1)) {
            buy = false
            earn += prices[i] - start
            continue
        }
    }
    return earn
}
```

