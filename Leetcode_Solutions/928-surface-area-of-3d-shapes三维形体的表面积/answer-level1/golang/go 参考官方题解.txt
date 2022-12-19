```
func surfaceArea(grid [][]int) int {
	var (
		dr      = []int{0, 1, 0, -1}
		dc      = []int{1, 0, -1, 0}
		n   int = len(grid)
		ans int = 0
	)
	for r := 0; r < n; r++ {
		for c := 0; c < n; c++ {
			if grid[r][c] > 0 {
				ans += 2
				for i := 0; i < len(dr); i++ {
					nr := r + dr[i]
					nc := c + dc[i]
					nv := 0
					if 0 <= nr && nr < n && 0 <= nc && nc < n {
						nv = grid[nr][nc]
					}
					ans += int(math.Max(float64(grid[r][c]-nv), float64(0)))
				}
			}
		}
	}
	return ans
}
```
