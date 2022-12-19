### 解题思路


### 代码

```golang
func isInterleave(s1 string, s2 string, s3 string) bool {
    if len(s1) + len(s2) != len(s3) {
        return false
    }
    var (
        dp = make([][]bool,len(s2)+1)
    )
    for i := 0; i < len(s2)+1; i ++ {
        dp[i] = make([]bool,len(s1)+1)
    }
    dp[0][0] = true
    for i := 1; i < len(s1)+1; i ++ {
        dp[0][i] = dp[0][i-1] && (s1[i-1] == s3[i-1])
    }
    for i := 1; i < len(s2)+1; i ++ {
        dp[i][0] = dp[i-1][0] && (s2[i-1] == s3[i-1])
    }
    for i := 1; i < len(s2)+1; i ++ {
        for j := 1; j < len(s1)+1; j ++ {
            dp[i][j] = (dp[i-1][j]&&s3[i+j-1]==s2[i-1]) || (dp[i][j-1]&&s3[i+j-1]==s1[j-1])
        }
    }
    return dp[len(s2)][len(s1)]
}
```