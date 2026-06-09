### 解题思路
逐个遍历，记录下当前位置的最大值和最小值，即得当前位置的最大利润。遍历完后，即得最大利润。

### 代码

```golang
func maxProfit(prices []int) int {
    if len(prices) < 1 {
        return 0
    }
    minPrice := prices[0]
    res := 0
    for _, v := range prices {
        if v < minPrice {
            minPrice = v
        }else if v - minPrice > res {
            res = v - minPrice
        }
    }
    return res
}
```