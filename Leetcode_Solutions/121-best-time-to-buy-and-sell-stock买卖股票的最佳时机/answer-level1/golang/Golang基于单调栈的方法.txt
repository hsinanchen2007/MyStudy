### 解题思路
时间复杂度100%

### 代码

```golang
func maxProfit(prices []int) int {
    if len(prices) < 2 {
        return 0
    }
    prices = append(prices,0)
    var (
        stack = []int{prices[0]}
        max = 0
        temp = 0
    )
    for i := 1;i < len(prices); i ++ {
        top := stack[len(stack)-1]
        for top > prices[i] {
            stack = stack[:(len(stack)-1)]
            if len(stack) == 0 {
                break
            }
            temp = top - stack[0]
            if temp > max {
                max = temp
            }
            top = stack[len(stack)-1]
        }
        stack = append(stack,prices[i])
    }
    return max
}
```