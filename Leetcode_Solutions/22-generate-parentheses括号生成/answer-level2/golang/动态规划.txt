### 解题思路
动态规划

### 代码

```golang
func generateParenthesis(n int) []string {
	if n == 0 {
		return []string{}
	}

	dp := [][]string{}
	dp0 := []string{""}
	dp = append(dp, dp0)

	for i := 1; i <= n; i++ {
		currentList := []string{}
		for j := 0; j < i; j++ {
			str1 := dp[j]
			str2 := dp[i-1-j]
			for _, s1 := range str1 {
				for _, s2 := range str2 {
					currentList = append(currentList, "("+s1+")"+s2)
				}
			}
		}
		dp = append(dp, currentList)
	}

	return dp[n]
}
```