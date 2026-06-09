算出每个位置的最小和。。。
```
func minimumTotal(triangle [][]int) int {
 	if len(triangle) == 0 {
		return 0
	}
	dp := make([][]int, len(triangle))
	for idx, v := range triangle {
		dp[idx] = make([]int, len(v))
	}
	dp[0][0] = triangle[0][0]
	l := len(triangle)
	for i := 1; i < l; i++ {
		for j := 0; j < len(dp[i]); j++ {
			if j-1 >= 0 && j < len(dp[i-1]) {
				m := int(math.Min(float64(dp[i-1][j-1]), float64(dp[i-1][j])))
				dp[i][j] = m + triangle[i][j]
			}else if j-1 < 0 {
				dp[i][j] = dp[i-1][j] + triangle[i][j]
			}else if j >= len(dp[i-1]) {
				dp[i][j] = dp[i-1][j-1] + triangle[i][j]
			}
		}
	}
	min := math.MaxInt64
	for _, v:= range dp[l-1] {
		if v < min {
			min = v
		}
	}
	return min
}
```
