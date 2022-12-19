```
func minimumTotal(triangle [][]int) int {
    if len(triangle) == 0 {
        return 0
    }
    dp := triangle[len(triangle) - 1]
    for i:=(len(triangle) - 2); i>=0; i-- {
        for j:=0; j<=i; j++ {
            dp[j] = min(dp[j], dp[j+1]) + triangle[i][j]
        }
    }
    return dp[0]
}

func min(a int, b int) int {
    if (a > b) {
        return b
    }
    return a
}
```
