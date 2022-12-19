![image.png](https://pic.leetcode-cn.com/487ea31a7006cdf65bf947b09427b2660d02f9331cb45b490e1818bdceb1428e-image.png)

动态规划 用第i天的卖出价格-(i-1)天内最小的买入价格

```
func maxProfit(prices []int) int {
    if len(prices) == 0 {
        return 0
    }
    
    thisProfit := 0 // 当前收益
    maxProfit := 0 // 最大收益
    min := prices[0] // 最小买入时的价格
    
    for _, v := range prices {
        if v < min {
            min = v
        }
        thisProfit = v-min
        if thisProfit > maxProfit {
            maxProfit = thisProfit
        }
    }
    return maxProfit
}
```

