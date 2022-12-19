### 解题思路
此处撰写解题思路

### 代码

```golang
func min(nums [3]int) int {
	res := 99999
	for _, v := range nums {
		if v < res {
			res = v
		}
	}
	return res
}

func minDistance(word1 string, word2 string) int {
	m, n := len(word1)+1, len(word2)+1
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
		dp[i][0] = i
	}
	for i := 0; i < n; i++ {
		dp[0][i] = i
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			tmp := dp[i-1][j-1] + 1
			if word1[i-1] == word2[j-1] {
				tmp = dp[i-1][j-1] + 0
			}
			dp[i][j] = min([3]int{dp[i-1][j] + 1, dp[i][j-1] + 1, tmp})
		}
	}
	return dp[m-1][n-1]
}
```