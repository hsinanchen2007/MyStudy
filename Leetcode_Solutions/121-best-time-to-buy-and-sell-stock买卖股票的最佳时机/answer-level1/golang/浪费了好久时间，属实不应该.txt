### 解题思路
此处撰写解题思路

### 代码

```golang
func maxProfit(prices []int) int {
    if len(prices) == 0  || len(prices) == 1{
        return 0
    }

    max := 0
    min := prices[0]
    for i := 1; i < len(prices); i++ {
        min = int(math.Min(float64(prices[i]), float64(min)))
        max = int(math.Max(float64(prices[i] - min), float64(max)))
        fmt.Println(min, max)
    }
    return max
}

```