### 解题思路
动态规划，状态方程：dp[i][j] == dp[i+1][j-1] && s[i] == s[j] if j - 1 > 1 else s[i] == s[j]
其中dp[i][j] 表示s[i:j+1] 是否为回文字符串

### 代码

```golang
func longestPalindrome(s string) string {
    n := len(s)
    if n <= 1 {
        return s
    }
    dp := makeArray(n, n)
    maxLen, result := 0, ""
    for j := 0; j < len(s); j++ {
        for i := 0; i <= j; i++ {
            if j - i > 1 {
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
            } else {
                dp[i][j] = s[i] == s[j]
            }
            if dp[i][j] {
                if j-i+1 > maxLen {
                    maxLen = j-i+1
                    result = s[i:j+1]
                }
            }
        }
    }
    return result
}

func makeArray(rows, cols int) [][]bool{
    m := make([][]bool, rows)
    for i := 0; i < rows; i ++ {
        m[i] = make([]bool, cols)
    }
    return m
}
```