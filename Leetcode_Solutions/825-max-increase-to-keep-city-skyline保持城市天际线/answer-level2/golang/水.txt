```go
func maxIncreaseKeepingSkyline(grid [][]int) int {
	xMaxs, yMaxs, res := make([]int, len(grid)), make([]int, len(grid[0])), 0
	for i := range grid {
		for j := range grid {
			if grid[i][j] > xMaxs[i] {
				xMaxs[i] = grid[i][j]
			}
			if grid[i][j] > yMaxs[j] {
				yMaxs[j] = grid[i][j]
			}
		}
	}

	for i := range grid {
		for j := range grid {
			if grid[i][j] < xMaxs[i] && grid[i][j] < yMaxs[j] {
				res += min(xMaxs[i], yMaxs[j]) - grid[i][j]
			}
		}
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```