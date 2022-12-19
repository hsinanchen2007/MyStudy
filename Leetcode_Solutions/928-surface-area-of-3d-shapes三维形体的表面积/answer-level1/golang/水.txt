### 解题思路
减去重合表面积

### 代码

```golang
func surfaceArea(grid [][]int) int {
	res := 0
	for i := range grid {
		for j := range grid {
			if grid[i][j] != 0 {
				res += 2 + grid[i][j]*4
			}
			if i > 0 {
				res -= 2*min(grid[i][j], grid[i-1][j])
			}
			if j > 0 {
				res -= 2*min(grid[i][j], grid[i][j-1])
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