```
func surfaceArea(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	if len(grid[0]) == 0 {
		return 0
	}
	row := len(grid)
	column := len(grid[0])
	c := 0
	for _, v := range grid {
		for _, v1 := range v {
			if v1 > 0 {
				c += v1
			}
		}
	}
	total := c*6

	visited := make([][]bool, row)
	for idx, _ := range grid {
		visited[idx] = make([]bool, column)
	}
	for i, v := range grid {
		for j, v1 := range v {
			if v1 > 0 && !visited[i][j] {
				total -= bfs(i,j,grid, visited)*2
			}
		}
	}
	return total
}

func bfs(i,j int,grid [][]int, visited [][]bool) int {
	row := len(grid)
	column := len(grid[0])
	c := 0.0
	queue := [][]int{[]int{i,j}}
	for len(queue) > 0 {
		temp := [][]int{}
		for _ , v := range queue {
			x, y := v[0], v[1]
			if visited[x][y] {
				continue
			}
			if x-1 >= 0 && !visited[x-1][y] {
				if grid[x-1][y] > 0 {
					c += math.Min(float64(grid[x][y]), float64(grid[x-1][y]))
					temp = append(temp, []int{x-1, y})
				}
			}

			if x+1 < row && !visited[x+1][y] {
				if grid[x+1][y] > 0 {
					c += math.Min(float64(grid[x][y]), float64(grid[x+1][y]))
					temp = append(temp, []int{x+1, y})
				}
			}

			if y+1 < column && !visited[x][y+1] {
				if  grid[x][y+1] > 0 {
					c += math.Min(float64(grid[x][y]), float64(grid[x][y+1]))
					temp = append(temp, []int{x, y+1})
				}
			}

			if y-1 >= 0 && !visited[x][y-1] {
				if  grid[x][y-1] > 0 {
					c += math.Min(float64(grid[x][y]), float64(grid[x][y-1]))
					temp = append(temp, []int{x, y-1})
				}
			}
			//加上往上叠的重复部分
			if grid[x][y] > 0 {
				c += float64(grid[x][y]-1)
			}
			visited[x][y] = true
		}
		queue = temp
	}
	return int(c)
}
```
