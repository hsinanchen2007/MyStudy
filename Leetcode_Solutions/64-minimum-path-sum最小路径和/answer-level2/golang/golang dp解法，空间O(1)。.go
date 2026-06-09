```
func minPathSum(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
    // 不需要额外的basecase，因为grid[0][0]就已经存储了basecase了

	for i:=1;i<m;i++ {
		grid[i][0] = grid[i][0] + grid[i-1][0]
	}
	for j := 1; j < n; j++ {
		grid[0][j] = grid[0][j] + grid[0][j-1]
	}

	for i:=1;i<m;i++{
		for j:=1;j<n;j++{
			grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j]
		}
	}
	return grid[m-1][n-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}else{
		return b
	}
}
```
