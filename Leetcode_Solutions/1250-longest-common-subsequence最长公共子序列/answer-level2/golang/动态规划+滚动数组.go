大多数解题方法都使用的是经典解法，这个题也在2019年上海交通大学计算机考研复试中出现了，但是对空间复杂度有要求，如果空间复杂度是
O(n^2) 不能拿满分，可以通过滚动数组优化，毕竟只是要求返回最长公共子序列长度而不要求返回具体的子序列，所以没必要申请那么大的二维数组。
代码块
func longestCommonSubsequence(text1 string, text2 string) int {
	m, n := len(text1), len(text2)
	dp := [2][1000]int{}
	k,l:=0,1
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if text1[i-1] == text2[j-1] {
				dp[k][j] = dp[l][j-1] + 1
			} else {
				dp[k][j] = max(dp[k][j-1], dp[l][j])
			}
		}
		k,l=l,k
	}
	return dp[l][n]
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
