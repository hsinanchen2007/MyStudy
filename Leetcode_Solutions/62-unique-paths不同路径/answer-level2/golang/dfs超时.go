

```

// 本题dfs会导致超时，所以应该用动态规划分解子问题
func uniquePaths(m int, n int) int {
	grid := make([][]int, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]int, m)
	}
	res := 0

	dfs := func(i, j int) {}
	dfs = func(i, j int) {
		if i == n-1 && j == m-1 {
			res++
			return
		}

		if i < 0 || j < 0 || i >= n || j >= m {
			return
		}

		if grid[i][j] == 1 {
			return
		}
		grid[i][j] = 1

		dfs(i, j+1)
		dfs(i+1, j)

		grid[i][j] = 0
	}
	dfs(0, 0)
	return res
}
```