```
func pondSizes(land [][]int) []int {

	result := make([]int, 0)
	m := len(land)
	for i, column := range land {
		n := len(column)
		for j, data := range column {
			if data == 0 {
				count := 0
				var dfs func(i int, j int)
				dfs = func(i int, j int) {
					if i >=m || i < 0 {
						return
					}
					if j >= n || j < 0 {
						return
					}

					if land[i][j] == 0 {
						count++
						land[i][j] = -1
						dfs(i + 1, j)
						dfs(i - 1, j)
						dfs(i, j + 1)
						dfs(i, j - 1)
						dfs(i - 1, j + 1)
						dfs(i - 1, j - 1)
						dfs(i + 1, j + 1)
						dfs(i + 1, j - 1)
					}
				}
				dfs(i, j)
				result = append(result, count)
			}
		}
	}

	sort.Ints(result)
	return  result
}
```
