### 解题思路
查找从第一天到倒数第二天，每天买入能赚取的最大值，再在每天赚取的最大值中挑选赚取最多的值。
这样做空间复杂度 n，时间复杂度 n方

### 代码

```golang
func maxProfit(prices []int) int {
    result := 0
    for i, v := range prices {
        if i+1 == len(prices) {
            return result
        }
        for _, v2 := range prices[i+1:] {
            if v2-v > result {
                result = v2-v
            }
        }
    }
    return result
}
```