golang解决　 1.dfs;    2.bfs

github: https://github.com/Crownt/leetcode

1.dfs

```go
var M int  // 行数
var N int  // 列数
var dir = [][]int{{1,0}, {-1,0}, {0,1}, {0,-1}}  // 四个方向

func maxAreaOfIsland(grid [][]int) int {

	max_area := 0
	M = len(grid)
	N = len(grid[0])

	for i:=0; i<M; i++ {
		for j:=0; j<N; j++ {
			area := dfs(grid, i, j)
			if area>max_area {
				max_area = area
			}
		}
	}

	return max_area
}

func dfs(grid [][]int, i int, j int) int{

	if grid[i][j]==0 || grid[i][j]==2 {
		return 0
	}

	grid[i][j] = 2  // 避免重复访问岛屿，沉岛思想
	area := 1
	for k:=0; k<4; k++ {
		next_i := i + dir[k][0]
		next_j := j + dir[k][1]

		if inArea(next_i, next_j) {
			area = area + dfs(grid, next_i, next_j)
		}
	}

	return area
}

func inArea(i int, j int) bool {
	return  i>=0 && i<M && j>=0 && j<N 
}
```
2.bfs

```go
var M_2 int  // 行数
var N_2 int  // 列数
var dir_2 = [][]int{{1,0}, {-1,0}, {0,1}, {0,-1}}  // 四个方向

func maxAreaOfIsland(grid [][]int) int {
	
	max_area := 0
	M_2 = len(grid)
	N_2 = len(grid[0])

	for i:=0; i<M_2; i++ {
		for j:=0; j<N_2; j++ {
			if grid[i][j] == 1 {
				area := bfs(grid, i, j)
				if area>max_area {
					max_area = area
				}
			}
		}
	}

	return max_area	
}

func bfs(grid [][]int, i int, j int) int {

	area := 0
	var q [][2]int  // 辅助队列，保存二维坐标

	// 入队前改变状态，避免重复入队
	grid[i][j] = 2
	q = append(q, [2]int{i, j})
	
	for len(q)!=0 {
		// 获得队首元素坐标后，将其出队
		x := q[0][0]
		y := q[0][1]
		q = q[1:]
		area++

		// 以出队元素为中心，向四周进行广度扩展
		for k:=0; k<4; k++ {
			next_i := x + dir_2[k][0]
			next_j := y + dir_2[k][1]

			if inArea_2(next_i, next_j) && grid[next_i][next_j]==1 {
				//　入队前改变状态，避免重复入队
				grid[next_i][next_j] = 2
				q = append(q, [2]int{next_i, next_j})				
			}
		}
	}

	return area
}

func inArea_2(i int, j int) bool {
	return  i>=0 && i<M_2 && j>=0 && j<N_2 
}
```

