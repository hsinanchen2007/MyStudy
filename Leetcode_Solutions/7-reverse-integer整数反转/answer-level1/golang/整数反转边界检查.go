### 解题思路
注意检查上溢和下溢的边界条件

### 代码

```golang
import (
    "math"
)
func reverse(x int) int {
    var result int
    var maxRes, minRes int = math.MaxInt32 %10, math.MinInt32 % 10
    var maxQ, minQ int = math.MaxInt32 / 10, math.MinInt32 / 10
    for x != 0 {
        res := x % 10
        //overflow MaxInt32
        if result > maxQ || (result == maxQ && res > maxRes) {
            return 0
        }
        //underflow MinInt32
        if result < minQ || (result == minQ) && res < minRes {
            return 0
        }
        result = result * 10 + res
        x = x/10
    }
    return result
}
```