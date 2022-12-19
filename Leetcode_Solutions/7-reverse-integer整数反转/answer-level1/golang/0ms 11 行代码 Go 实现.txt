
![7t0ms.png](https://pic.leetcode-cn.com/8b642f90a65141f08d30b8705f78bb83d1a0230bdb22b32c6ca452d33c96a078-7t0ms.png)

Go 的取模运算很方便，不用单独判断正负了。

代码：
```
func reverse(x int) int {
    y := 0
    for x!=0 {
        y = y*10 + x%10
        if !( -(1<<31) <= y && y <= (1<<31)-1) {
            return 0
        }
        x /= 10
    }
    return y
}
```