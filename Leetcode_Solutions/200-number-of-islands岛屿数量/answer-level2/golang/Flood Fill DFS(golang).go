### 解题思路
Flood Fill DFS

### 代码

```golang
func numIslands(grid [][]byte) int {
	if len(grid) == 0 {
		return 0
	}
	result, m, n := 0, len(grid), len(grid[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			result += dfs(grid, m, n, i, j)
		}
	}
	return result
}

func dfs(grid [][]byte, m, n, i, j int) int {
	if i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' {
		return 0
	}
	grid[i][j] = '0'
	dfs(grid, m, n, i-1, j)
	dfs(grid, m, n, i+1, j)
	dfs(grid, m, n, i, j-1)
	dfs(grid, m, n, i, j+1)
	return 1
}
```