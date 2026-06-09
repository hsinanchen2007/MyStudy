状态定义：dp[i][j]表示s[i...j]这个子串的最长回文序列

状态转移方程：

当s[i]==s[j], dp[i][j]= dp[i+1][j-1] + 2 ;

 当s[i]!=s[j], dp[i][j] = max(dp[i+1][j], dp[i][j-1]) ，其中dp[i+1][j]表示选择s[j]， dp[i][j-1]表示跳过s[j]

``` go
func max(nums ...int) int {
	m := nums[0]
	for _, n := range nums {
		if m < n {
			m = n
		}
	}
	return m
}

func longestPalindromeSubseq(s string) int {
	n := len(s)

	if n < 2 {
		return n
	}

	dp := [1000][1000]int{}
	for i := 0; i < n; i++ {
		dp[i][i] = 1
	}

	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				dp[i][j] = dp[i+1][j-1] + 2
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1])
			}
		}

	}

	return dp[0][n-1]
}
```