```go []
func maxAreaOfIsland(grid [][]int) int {
	if grid == nil {
		return 0
	}
	R := len(grid) // 行数
	if R == 0 {
		return 0
	}

	C := len(grid[0]) // 列数
	if C == 0 {
		return 0
	}

	// 解决最大岛屿问题-转换成图论问题
	G := constructGraph(R, C, grid)

	res := 0
	visited := make(map[int]bool, len(G))

	for v := 0; v < len(G); v++ {
		x, y := v/C, v%C
		if grid[x][y] == 1 && !visited[v] {
			res = int(math.Max(float64(res), float64(dfs(v, visited, G))))
		}
	}
	return res
}

func dfs(v int, visited map[int]bool, G []*list.List) int {
	visited[v] = true
	res := 1
	for w := G[v].Front(); w != nil; w = w.Next() {
		p := w.Value.(int)
		if !visited[p] {
			res += dfs(p, visited, G)
		}
	}
	return res
}

func constructGraph(R, C int, grid [][]int) []*list.List {
	dirs := [][]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
	g := make([]*list.List, 0) // 是一个链表数组
	for i := 0; i < R*C; i++ {
		g = append(g, list.New()) // 第i个元素表示的是第i个顶点和它相邻的顶点
	}

	for v := 0; v < len(g); v++ {
		x, y := v/C, v%C
		if grid[x][y] == 1 { // 1表示是陆地
			for d := 0; d < 4; d++ { // 4联通
				nextx, nexty := x+dirs[d][0], y+dirs[d][1]
				if inArea(nextx, nexty, R, C) && grid[nextx][nexty] == 1 {
					next := nextx*C + nexty
					g[v].PushBack(next)
					g[next].PushBack(v)
				}
			}
		}
	}
	return g
}

func inArea(x, y, R, C int) bool {
	return x >= 0 && x < R && y >= 0 && y < C
}
```

```go []
func maxAreaOfIsland(grid [][]int) int {
	// 不显示的创建图来解决-floodfill算法
	if grid == nil {
		return 0
	}
	R := len(grid) // 行数
	if R == 0 {
		return 0
	}

	C := len(grid[0]) // 列数
	if C == 0 {
		return 0
	}

	res := 0
	visited := make([][]bool, 0)
	for range make([]int, R) { // 初始化空的 visited 二维数组
		visited = append(visited, make([]bool, C))
	}

	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			if !visited[i][j] && grid[i][j] == 1 {
				res = int(math.Max(float64(res), float64(dfs(i, j, R, C, visited, grid))))
			}
		}

	}
	return res
}

func dfs(x, y, R, C int, visited [][]bool, grid [][]int) int {
	dirs := [][]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
	visited[x][y] = true
	res := 1
	for d := 0; d < 4; d++ {
		nextx, nexty := x+dirs[d][0], y+dirs[d][1]
		// 1. 合法 2. 未被遍历过 3. 是陆地
		if inArea(nextx, nexty, R, C) && !visited[nextx][nexty] && grid[nextx][nexty] == 1 {
			res += dfs(nextx, nexty, R, C, visited, grid)
		}
	}
	return res
}

func inArea(x, y, R, C int) bool {
	return x >= 0 && x < R && y >= 0 && y < C
}
```