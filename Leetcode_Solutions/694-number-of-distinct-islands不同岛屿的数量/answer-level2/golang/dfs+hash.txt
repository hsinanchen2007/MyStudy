### 解题思路
此处撰写解题思路


### 代码

```golang

func numDistinctIslands(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	r := len(grid)
	c := len(grid[0])

	m := make(map[string]struct{})
	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if grid[i][j] == 1 {
				record := make([]byte, 0)
				record = dfs(grid, record, i, j, i, j)
				if len(record) > 0 {
					m[string(record)] = struct{}{}
				}

			}

		}
	}

	return len(m)
}

func dfs(grid [][]int, record []byte, i, j, basei, basej int) []byte {
	grid[i][j] = 0
	record = append(record, byte(i-basei))
	record = append(record, byte(j-basej))
	if i-1 >= 0 && grid[i-1][j] == 1 {
		record = dfs(grid, record, i-1, j, basei, basej)
	}

	if i+1 < len(grid) && grid[i+1][j] == 1 {
		record = dfs(grid, record, i+1, j, basei, basej)
	}

	if j-1 >= 0 && grid[i][j-1] == 1 {
		record = dfs(grid, record, i, j-1, basei, basej)
	}

	if j+1 < len(grid[0]) && grid[i][j+1] == 1 {
		record = dfs(grid, record, i, j+1, basei, basej)
	}

	return record
}

```