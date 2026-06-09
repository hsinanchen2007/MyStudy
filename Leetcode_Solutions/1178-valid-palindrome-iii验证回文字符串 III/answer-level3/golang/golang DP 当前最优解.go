### 解题思路
t为s的反向字符串
dp[i][j]表示，s的前i位及t的前j位中，一共有多少个相同字符
dp[len(s)][len(s)]则表示了s能表达的最长回文字符串长度
当len(s)-dp[len(s)][len(s)] <= k时，说明通过移除最多k个元素，可以将s转变为一个回文字符串

### 代码
执行用时 :8 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :6.4 MB, 在所有 Go 提交中击败了100.00%的用户
```golang
func isValidPalindrome(s string, k int) bool {
	n := len(s)
	dp := make([][]int, n+1)
	for i,_ := range dp{
		dp[i] = make([]int, n+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if s[i-1] == s[n-1-(j-1)]{
				dp[i][j] = dp[i-1][j-1] + 1
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	return len(s) - dp[n][n] <= k
}

func max(a, b int) int {
	if a > b {
		return a
	}else{
		return b
	}
}
```