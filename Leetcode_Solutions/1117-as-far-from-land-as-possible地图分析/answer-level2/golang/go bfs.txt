```

type point struct {
	x, y int
}

func maxDistance(grid [][]int) int {
	m := len(grid)
	queue := make([]*point, 0)
	for i := 0; i < m; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 {
				queue = append(queue, &point{x: i, y: j})
			}
		}
	}
	if len(queue) == 0 || len(queue) == m*m {
		return -1
	}
	distance := 0
	for len(queue) != 0 {
		tmp := queue
		queue = []*point{}
		for _, v := range tmp {
			r := v.x
			l := v.y
			// 遍历上方单元格
			if r-1 >= 0 && grid[r-1][l] == 0 {
				grid[r-1][l] = 2
				queue = append(queue, &point{x: r - 1, y: l})
			}
			// 遍历下方单元格
			if r+1 < m && grid[r+1][l] == 0 {
				grid[r+1][l] = 2
				queue = append(queue, &point{x: r + 1, y: l})
			}
			// 遍历左边单元格
			if l-1 >= 0 && grid[r][l-1] == 0 {
				grid[r][l-1] = 2
				queue = append(queue, &point{x: r, y: l - 1})
			}
			// 遍历右边单元格
			if l+1 < m && grid[r][l+1] == 0 {
				grid[r][l+1] = 2
				queue = append(queue, &point{x: r, y: l + 1})
			}
		}
		if len(queue) != 0 {
			distance++
		}
	}
	if distance == 0 {
		return -1
	}
	return distance
}

```
