dp[i][j]表示s1[:i+1]和s2[:j+1]的最短编辑距离
对i和j有以下几种情况：
- dp[i][j] = dp[i-1][j]+1：删除字符
- dp[i][j] = dp[i][j-1]+1：插入字符
- dp[i][j] = dp[i-1][j-1]+1：替换字符

```golang
func minDistance(s1, s2 string) int {
	ln1 := len(s1)
	ln2 := len(s2)
	if ln1 == 0 {
		return ln2
	} else if ln2 == 0 {
		return ln1
	}

	dp := make([][]int, ln1+1)
	dp[0] = make([]int, ln2+1)
	for i := 0; i < ln1+1; i++ {
		dp[i] = make([]int, ln2+1)
	}
	for i := 1; i < ln1+1; i++ {
		dp[i][0] = i
	}
	for i := 1; i < ln2+1; i++ {
		dp[0][i] = i
	}

	for i := 1; i < ln1+1; i++ {
		for j := 1; j < ln2+1; j++ {
			if s1[i-1] == s2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1
			}
		}
	}

	return dp[ln1][ln2]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
```