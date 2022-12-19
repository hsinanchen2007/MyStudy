### 解题思路
```
执行用时 :
0 ms
, 在所有 golang 提交中击败了
100.00%
的用户
内存消耗 :
2 MB
, 在所有 golang 提交中击败了
13.04%
的用户
```

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