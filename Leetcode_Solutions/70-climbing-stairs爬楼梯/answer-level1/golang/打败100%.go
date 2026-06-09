func climbStairs(n int) int {
    if n <= 2 {
        return n
    }
    dp := make([]int, n)
    
    for i:=1;i<=n;i++{
        if i <= 2 {
            dp[i-1] = i
        } else {
            dp[i-1] = dp[i-2] + dp[i-3]
        }
    }

    return dp[n-1]

}