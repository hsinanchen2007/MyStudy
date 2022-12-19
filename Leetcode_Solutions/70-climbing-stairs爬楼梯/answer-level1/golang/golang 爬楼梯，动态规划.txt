### 解题思路
// 最优子结构、无后效性、重叠子问题
// 拆分问题为子问题
// 最后一步走到楼顶有两种情况 f(n-1), f(n-2)
// fn = f(n-1) + f(n-2)
// 时间复杂度O(n)、空间复杂度O(1)

### 代码

```golang
func climbStairs(n int) int {
    if n < 3 {
        return n
    }
    a, b := 1, 2
    for i := 3; i < n; i++ {
       a, b = b, a + b
    }
    return a + b
}
```
