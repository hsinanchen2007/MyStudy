### 解题思路
此处撰写解题思路

### 代码

```golang
func pow3N(n int) int {
    res := 1
    for i := 0; i < n; i++{
        res *= 3
    }
    return res
}
func integerBreak(n int) int {
    if n <= 3 {
        return n-1
    }
    a, b := n/3, n%3
    if b == 0{
        return pow3N(a)
    }
    if b == 1 {
        return pow3N(a-1)*4
    }
    return pow3N(a) * 2
}
```