
```
func numIslands(grid [][]byte) int {
	var row = len(grid)
	if row <= 0 {
		return 0;
	}
	var col = len(grid[0])
	var visited = make([][]int, row)
	for i := 0; i < row; i++ {
		visited[i] = make([]int, col)
	}
	var sum = 0
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if visited[i][j] == 1 {
				continue
			}
			if grid[i][j] == '0' {
				continue
			}
			sum++ // 语句不能赋值
			//bfs(grid, visited, i, j, row, col) // 20ms  6 MB
            dfs(grid, visited, i, j, row, col) // 0ms 3.4 MB
		}
	}
	return sum
}

// dfs遍历
func dfs(grid [][]byte, visited [][]int, x, y int, row, col int) {
	if x < 0 || y < 0 || x >= row || y >= col {
		return
	}
	if grid[x][y] == '0' {
		return
	}
	if visited[x][y] == 1 {
		return
	}
	visited[x][y] = 1
	dfs(grid, visited, x-1, y, row, col)
	dfs(grid, visited, x, y-1, row, col)
	dfs(grid, visited, x+1, y, row, col)
	dfs(grid, visited, x, y+1, row, col)
}

type elem []int
// BFS实现遍历
func bfs(grid [][]byte, visited [][]int, i, j int, row, col int) {
	l := list.New()
	var ele = elem{i, j}
	l.PushBack(ele)

	for l.Len() != 0 {
		element, _ := (l.Front()).Value.(elem)
		i, j = element[0], element[1]  // 更新当前节点索引
		visited[element[0]][element[1]] = 1
		fmt.Println(l.Remove(l.Front()))
		up := i-1
		down := i+1
		left := j-1
		right := j+1
		// 注意防止重复加入队列中
		if up >= 0 && up <row && grid[up][j] == '1' && visited[up][j] == 0 {
			tmp := elem{up, j}
			l.PushBack(tmp)
			visited[up][j] = 1
		}
		if down >= 0 && down < row && grid[down][j] == '1' && visited[down][j] == 0 {
			tmp := elem{down, j}
			l.PushBack(tmp)
			visited[down][j] = 1
		}
		if left >= 0 && left < col && grid[i][left] == '1' && visited[i][left] == 0 {
			tmp := elem{i, left}
			l.PushBack(tmp)
			visited[i][left] = 1
		}
		if right >= 0 && right < col && grid[i][right] == '1' && visited[i][right] == 0 {
			tmp := elem{i, right}
			l.PushBack(tmp)
			visited[i][right] = 1
		}

	}
}
```