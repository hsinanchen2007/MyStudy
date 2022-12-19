- golang
- 动态规划
- 重点区分n<=3时最大乘积dp[n] < n, 需要使用n

``` golang
func integerBreak(n int) int {
    return method_dp(n)
}

/*
原因：n <=3 时 最大乘积dp[n] < n，因此需要使用max(n, dp[n])
dp[i] = getMax(dp[i], i > j ==> j * max(i-j, dp[i-j]))
*/
func method_dp(n int) int {
    dp := make([]int, n+1)
    dp[1] = 1
    dp[2] = 1
    for i := 3; i <=n; i++ {
        for j := 1; j < i; j++ {
            dp[i] = getMax(dp[i], j * getMax(i-j, dp[i-j]))
        }
    }
    // fmt.Println(dp)
    return dp[n]
}

func getMax(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```
