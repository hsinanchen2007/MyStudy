### 解题思路
执行内存 : 0 ms , 在所有 Go 提交中击败了 100.00% 的用户
内存消耗 : 1.9 MB , 在所有 Go 提交中击败了 100.00% 的用户
### 代码

```golang
func numTrees(n int) int {
    dp := make([]int, n + 1)
    dp[0] = 1
    dp[1] = 1
    for i := 2; i < n + 1; i++ {
        for j := 1; j < i + 1; j++ {
            dp[i] = dp[i] + dp[j - 1] * dp[i - j]
        } 
    }
    return dp[n]
}
```