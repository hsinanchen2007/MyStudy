### 解题思路
有点类似于链表

### 代码

```golang
func fib(N int) int {
    memo := make([]int, N + 1)
    return recur(N, memo)
}

func recur(n int, memo []int) int {
    if n <= 1 {
        return n
    }
    if memo[n] == 0 {
        memo[n] = recur(n-1, memo) + recur(n-2, memo)
        return memo[n]
    }
    return memo[n]
}
```