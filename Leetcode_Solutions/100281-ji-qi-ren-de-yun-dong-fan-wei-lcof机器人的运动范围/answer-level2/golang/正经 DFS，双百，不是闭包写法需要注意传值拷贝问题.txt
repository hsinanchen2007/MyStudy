``` go
func movingCount(m int, n int, k int) int {
	if m > 100 || n > 100 || k > 20 {
		return 0
	}
	var visited [100][100]bool
	return dfs(0, 0, m, n, k, &visited)
}

func dfs(x, y, m, n, k int, visited *[100][100]bool) int {
	if x >= m || y >= n || (x%10+x/10+y%10+y/10) > k || visited[x][y] {
		return 0
	}
	visited[x][y] = true
	return dfs(x+1, y, m, n, k, visited) + dfs(x, y+1, m, n, k, visited) + 1
}
```