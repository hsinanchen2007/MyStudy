### 解题思路
最优子结构
无后效性
重叠子问题

### 代码

```golang
func fib(n int) int {
    if n < 2 { return n }
    pre, curr := 0, 1
    for i := 2; i <= n; i++ {
        pre, curr = curr, (pre + curr) % 1000000007
    }
    return curr 
}
```