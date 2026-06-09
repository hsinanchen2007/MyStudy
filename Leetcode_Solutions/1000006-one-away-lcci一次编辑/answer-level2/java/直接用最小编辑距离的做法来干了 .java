```go
func oneEditAway(first string, second string) bool {
    minDistance := minDistance(first, second)
    if minDistance > 1 {
        return false
    }
    return true
}
func minDistance(word1 string, word2 string) int {
    m := len(word1)
    n := len(word2)
    w1 := []byte(word1)
    w2 := []byte(word2)
    var dp [][] int
    for i := 0; i <= m; i++ {
        temp := make([]int, n + 1)
        dp = append(dp, temp)
    }
    for i := 0; i <= m; i++ {
        dp[i][0] = i
    }
    for j := 0; j <= n; j++ {
        dp[0][j] = j
    }
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if w1[i - 1] == w2[j - 1] {
                dp[i][j] = dp[i - 1][j - 1]
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))
            }
        }
    }
    return dp[m][n]
    
}
func min(a int, b int) int {
    if a > b {
        return b
    }
    return a
}
```