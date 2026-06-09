### 解题思路
目标：找一个最小值和一个最大值，其中最大值必须在最小值的右侧，这样才能算出最大差值
思路：
max记录最大值，min记录最小值，maxVal记录最大差值，默认都是0
从后向前，遇到比max大的值，那么max和min都赋值为这个值（齐头并进）
         遇到比min小的值，那么min赋值（只有min更新），并计算一次max - min，如果大于maxVal，则赋值maxVal

### 代码

```golang
func maxProfit(prices []int) int {
    var max, min, maxVal int
    for i:= len(prices) - 1; i >= 0; i-- {
        if prices[i] > max {
            max = prices[i]
            min = max
        } else if prices[i] < min {
            min = prices[i]
            if val := max - min; val > maxVal {
               maxVal = val
            }
        }
    }
    return maxVal
}
```