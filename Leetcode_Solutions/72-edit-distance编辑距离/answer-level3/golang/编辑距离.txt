动态规划加空间压缩，时间复杂度为O(MN),空间复杂度为O(min{M,N}).
func minDistance(word1 string, word2 string) int {
	m := len(word1)
	n := len(word2)
	if m == 0 && n == 0 {
		return 0
	}
	dp := make([]int, n+1)
	var temp int
	dp[0] = 0
	for j := 1; j <= n; j++ {
		dp[j] = j
	}
	for i := 1; i <= m; i++ {
		temp = dp[0]  //记录的值
		dp[0] = i  //更新第一个值
		for j := 1; j <= n; j++ {
			var res int //
			if j > 0 {
				res = dp[j]  //存储临时值
			}
			if word1[i-1] == word2[j-1] {
				dp[j] = temp
			} else if dp[j-1] == dp[j] {
				dp[j] = temp + 1
			} else {
				dp[j] = minNum(dp[j], dp[j-1]) + 1
			}
			temp = res
		}
		fmt.Println(dp)
	}
	return dp[n]
}

func minNum(a, b int) int {
	if a > b {
		return b
	}
	return a
}

这里偷懒了，没有建立dp[min{M,N}]的动态数组，直接假设M > N，原理是一样的