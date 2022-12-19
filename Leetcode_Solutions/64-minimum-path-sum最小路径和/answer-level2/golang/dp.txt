状态转移方程 dp[i][j] = min(current+dp[i-1][j], current+dp[i][j-1])
```
func minPathSum(grid [][]int) int {
    if len(grid) == 0 {
		return 0
	}
	column := len(grid)
	row := len(grid[0])

	dp := make([][]int, column)
	for idx, _ := range dp {
		dp[idx] = make([]int, row)
	}
	sum := 0
	for idx,v:=range grid[0] {
		sum+=v
		dp[0][idx] = sum
	}
	sum = 0
	for idx, v:=range grid {
		sum += v[0]
		dp[idx][0] = sum
	}

	for i := 1; i < column; i++ {
		for j := 1; j < row; j++ {
			s := grid[i][j]
			left := dp[i][j-1]
			top := dp[i-1][j]
			dp[i][j] = int(math.Min(float64(s+left),float64(s+top)))
		}
	}
	return dp[column-1][row-1]
}
```
