两点 `A(x0, y0) B(x1, y1)` 确定一条直线， 直线的斜率为 `k =  (y1 - y0) / (x1 - x0)`
所以我们只要遍历数组，判断当前点和上个点构成的直线的斜率是否和之前相同即可。

这里不需要求出 k，因为直接求出 k 可能为浮点数，不一定精确，所以我们用交叉相乘判断相等即可

```
func checkStraightLine(coordinates [][]int) bool {
    c := coordinates
    x, y := c[1][0] - c[0][0], c[1][1] - c[0][1]
    for i := 2; i < len(c); i++ {
        x1, y1 := c[i][0] - c[i-1][0], c[i][1] - c[i-1][1]
        if x1 * y != x * y1 {
            return false
        }
    }
    return true
}
```
