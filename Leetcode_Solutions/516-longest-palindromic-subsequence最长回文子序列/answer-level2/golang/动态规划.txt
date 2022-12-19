dp[i][j] 保存的是s[i:j+1]子串的最长回文子序列的长度， 只用到dp二维矩阵的左上部分
最小子问题为j-i=1时,dp[i][i+1] = dp[i+1][i] + 2或者dp[i][i+1] = max(dp[i+1][i+1], dp[i][i]) 此时全部子问题为已知解。

```
// s[i]==s[j] dp[i][j] = dp[i+1][j-1] +2
// s[i] != s[j] dp[i][j] = max(dp[i+1][j], dp[i][j-1])
func longestPalindromeSubseq(s string) int {
	l := len(s)
	// dp[i][j] 保存的是s[i:j+1]子串的最长回文子序列的长度， 只用到dp二维矩阵的左上部分
	dp := make([][]int, l)
	for i := 0; i < l; i++ {
		dp[i] = make([]int, l)
		dp[i][i] = 1
	}
	// i和j的距离从1开始递增
	for dis := 1; dis < l; dis++ {
		for i := 0; i + dis < l; i++{
			j := i + dis
			if s[i] == s[j] {
				dp[i][j] = 2 + dp[i+1][j-1]
			} else {
				dp[i][j] = Max(dp[i+1][j], dp[i][j-1])
			}
		}
	}

	return dp[0][l-1]
}

func Max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
```