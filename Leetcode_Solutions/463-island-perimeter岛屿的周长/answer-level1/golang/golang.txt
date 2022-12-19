```
func islandPerimeter(grid [][]int) int {
	res := 0

	for i := range grid {
		for j, val := range grid[i] {
			if val == 0 {
				continue
			}

			if (i - 1) >= 0 {
				if grid[i-1][j] == 0 {
					res++
				}
			} else {
				res++
			}

			if (i + 1) < len(grid) {
				if grid[i+1][j] == 0 {
					res++
				}
			} else {
				res++
			}

			if (j - 1) >= 0 {
				if grid[i][j-1] == 0 {
					res++
				}
			} else {
				res++
			}

			if (j + 1) < len(grid[i]) {
				if grid[i][j+1] == 0 {
					res++
				}
			} else {
				res++
			}

		}
	}

    return res
}
```