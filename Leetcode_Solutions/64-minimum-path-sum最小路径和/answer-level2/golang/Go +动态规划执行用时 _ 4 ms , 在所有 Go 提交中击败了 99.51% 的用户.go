### 解题思路
动态规划，利用dp[][]数组
每个点的最优解只能是左边或者上边过来的

### 代码

```golang

func minPathSum(grid [][]int) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	row := len(grid)
	column := len(grid[0])
	dp := make([][]int, row)
	for i := 0; i < row; i++ {
		dp[i] = make([]int, column)
	}
	dp[0][0] = grid[0][0]
	for i := 1; i < column; i++ {
		dp[0][i] = dp[0][i-1] + grid[0][i]
	}
	for i := 1; i < row; i++ {
		dp[i][0] = dp[i-1][0] + grid[i][0]
		for j := 1; j < column; j++ {
			// 由左或者上转化过来
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
		}
	}
	return dp[row-1][column-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

```