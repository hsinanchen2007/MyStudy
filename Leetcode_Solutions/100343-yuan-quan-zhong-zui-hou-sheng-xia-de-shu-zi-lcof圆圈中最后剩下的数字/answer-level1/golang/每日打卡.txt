### 解题思路

### 代码

```golang
func lastRemaining(n int, m int) int {
    flag := 0
    for i := 2; i <= n; i++ {
        flag = (flag + m) % i
        //动态规划的思想，将f(n,m)替换成flag存储
    }
    return flag
}
```