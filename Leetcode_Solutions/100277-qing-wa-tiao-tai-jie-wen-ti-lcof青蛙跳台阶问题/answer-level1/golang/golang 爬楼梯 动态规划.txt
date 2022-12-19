### 解题思路
n == 0, 返回 1。😒

动态规划要点复习：
最优子结构
无后效性
重复子问题

### 代码

```golang
func numWays(n int) int {
    if n == 0 { 
        return 1
    }
    if n == 1 {
        return 1
    }
    if n == 2 {
        return 2
    }
    pre, curr := 1, 2
    for i := 3; i <= n; i++ {
        pre, curr = curr, (pre + curr) % 1000000007
    }
    return curr
}
```