
```
import "math"
func longestCommonSubsequence(text1 string, text2 string) int {
    c1 := []byte(text1)
    c2 := []byte(text2)
    
    m := len(c1)
    n := len(c2)
    
    dp := make([][]int, m+1)
    for i := range dp {
        dp[i] = make([]int, n+1)
    }
    
    dp[0][0] = 0
    
    for i:= 1; i < m+1 ; i++ {
        for j := 1; j < n+1; j++ {
            if c1[i-1] == c2[j-1] {
                dp[i][j] = dp[i-1][j-1] + 1
            } else {
                dp[i][j] = int(math.Max(float64(dp[i-1][j]), float64(dp[i][j-1])))
            }
        } 
    }
    return dp[m][n]
}
```
