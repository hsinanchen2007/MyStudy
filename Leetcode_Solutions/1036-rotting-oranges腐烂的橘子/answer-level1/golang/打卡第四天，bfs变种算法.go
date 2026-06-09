### 解题思路
bfs变种算法
### 代码

```golang
func orangesRotting(grid [][]int) int {
	var rows = len(grid)
	var cols = len(grid[0])
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j ++ {
			if grid[i][j] == 2 {
				bfs(grid, i, j, rows, cols, 2)
			}
		}
	}
	var max = 0
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] == 1 {
				return -1
			}
			if max < grid[i][j] {
				max = grid[i][j]
			}
		}
	}
    if max == 0 {
		return 0
	}
	return max - 2
}

func bfs(grid [][]int, i, j int, rows, cols int, depth int) {
	grid[i][j] = depth
	if i > 0 && (grid[i-1][j] == 1 || grid[i-1][j]-grid[i][j] > 1) {
		bfs(grid, i-1, j, rows, cols, depth+1)
	}
	if i < rows-1 && (grid[i+1][j] == 1 || grid[i+1][j]-grid[i][j] > 1) {
		bfs(grid, i+1, j, rows, cols, depth+1)
	}
	if j > 0 && (grid[i][j-1] == 1 || grid[i][j-1]-grid[i][j] > 1) {
		bfs(grid, i, j-1, rows, cols, depth+1)
	}
	if j < cols-1 && (grid[i][j+1] == 1 || grid[i][j+1]-grid[i][j] > 1) {
		bfs(grid, i, j+1, rows, cols, depth+1)
	}
}
```