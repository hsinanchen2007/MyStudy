
```

// 动态规划
// 动态规划

// dp[i][j] 代表 T 前 i 字符串可以由 S 的前 j 个字符串组成最多个数.

// 所以动态方程:

// 当 S[j] == T[i] , dp[i][j] = dp[i-1][j-1] + dp[i][j-1];

// 当 S[j] != T[i] , dp[i][j] = dp[i][j-1]

func numDistinct(s string, t string) int {

	dp := make([][]int, len(t)+1)
	for i := 0; i < len(t)+1; i++ {
		dp[i] = make([]int, len(s)+1)
	}
	for i := 0; i < len(s)+1; i++ {
		dp[0][i] = 1
	}
	for i := 0; i < len(t)+1; i++ {
		dp[i][0] = 0
	}
    dp[0][0] = 1

	for i := 1; i < len(t)+1; i++ {
		for j := 1; j < len(s)+1; j++ {
			if t[i-1] == s[j-1] {
				dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
			} else {
				dp[i][j] = dp[i][j-1]
			}
			
		}
	}
	return dp[len(t)][len(s)]

}

```