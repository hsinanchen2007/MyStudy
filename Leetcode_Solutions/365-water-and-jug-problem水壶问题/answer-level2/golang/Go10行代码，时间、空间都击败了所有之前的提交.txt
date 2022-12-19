### 解题思路
首先考虑边界， x， y， z有0的情况（有负数的情况这里不用考虑）和 x+y < z的情况
其次是合规的输入，参考题解第一条的说明， z必须是gcd(x, y)的倍数
用辗转相除法实现gcd

### 代码

```golang
func canMeasureWater(x int, y int, z int) bool {
    return z==0 || (x+y >= z && z % gcd(x, y) == 0)
}

func gcd (a, b int) int {
    for b != 0 {
        a, b = b, a % b
    }
    return a
}
```