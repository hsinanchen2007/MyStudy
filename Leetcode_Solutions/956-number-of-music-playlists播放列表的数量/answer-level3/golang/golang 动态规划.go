```
func numMusicPlaylists(N int, L int, K int) int {
    mod := 1000000007
    dp := make([][]int, N + 1)
    for i := 1; i <= N; i++ {
        dp[i] = make([]int, L + 1)
    }
    
    for i := K + 1; i <= N; i++ {
        for j := i; j <= L; j++ {
            if i == j || i == K + 1 {
                dp[i][j] = factorial(i) % mod
            } else {
                dp[i][j] = (dp[i-1][j-1] * i + dp[i][j-1] * (i - K)) % mod
            }
        }
    }
    return dp[N][L]
}

func factorial(x int) int {
    ret := 1
    for i := 1; i <= x; i++ {
        ret  = ret * i % 1000000007
    }
    return ret 
}
```
