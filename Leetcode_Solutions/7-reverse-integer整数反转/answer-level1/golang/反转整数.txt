### 解题思路
注意边界条件的判断

### 代码

```golang
var maxRes, minRes int = math.MaxInt32 %10, math.MinInt32 % 10
var maxQ, minQ int = math.MaxInt32 / 10, math.MinInt32 / 10
 
func reverse(x int) int {
    var negative bool = false
    if x < 0 {
        x = x * (-1)
        negative = true
    }
    var result int = 0
    for x > 0 {
        if (result >= maxQ && x % 10 >= maxRes) || result > maxQ {
            result = 0
            break
        }
        result = result * 10 + x % 10 
        x = x / 10
    }
    if negative {
        result = -1 * result
    }
    return result
}
```