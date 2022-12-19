每次循环中dp[i][j]的取值只和三个变量有关系：dp[i-1][j-1],dp[i][j-1],dp[i-1][j] ，所以用a,c,b三个临时变量取代它们，但是需要维持一个一维数组up来记录变量b的变化，因为下一次外部循环开始后需要up来给b赋值
```
func longestCommonSubsequence(text1 string, text2 string) int {
	m, n := len(text1), len(text2)
	up := make([]int, n+2)
	var a, b, c, tmp, maximum int
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if text1[i-1] == text2[j-1] {
				tmp = a + 1
			} else {
				tmp = max(b, c)
			}
			if tmp > maximum {
				maximum = tmp
			}
			c = tmp
			a = b
			up[j] = tmp
			b = up[j+1]
		}
		a = 0
		b = up[1]
		c = 0
	}
	return maximum
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```
