func surfaceArea(grid [][]int) int {
	total := 0
	N := len(grid)
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			// 上下左右
			if grid[i][j] == 0 {
				continue
			}
			total = total + 2 + grid[i][j]*4
			if i > 0 && grid[i-1][j] > 0 {
				total = total - min(grid[i-1][j], grid[i][j]) * 2
			}
			if j > 0 && grid[i][j-1] > 0 {
				total = total - min(grid[i][j-1], grid[i][j]) * 2 
			}
		}
	}
	return total
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
