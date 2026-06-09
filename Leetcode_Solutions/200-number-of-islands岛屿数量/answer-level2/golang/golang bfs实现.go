### 解题思路
此处撰写解题思路

### 代码

```golang
type point struct {
	x int
	y int
}

func numIslands(grid [][]byte) int {
	ret := 0
	directs := [][]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}

	if len(grid) == 0 {
		return 0
	}

	xLen := len(grid)
	yLen := len(grid[0])

	walk := func(x int, y int) bool {
		// 为什么把 '0' 改成 0 就会失败呢？
		if x >= xLen || x < 0 || y < 0 || y >= yLen || grid[x][y] == '0' {
			return false
		}
		grid[x][y] = '0'
		return true
	}

	for {
		var queue []point
		for i := 0; i < xLen; i++ {
			for j := 0; j < yLen; j++ {
				if walk(i, j) {
					queue = append(queue, point{i, j})
					break
				}
			}
			if len(queue) != 0 {
				break
			}
		}

		if len(queue) == 0 {
			break
		}

		for len(queue) > 0 {
			tmp := queue[0]
			for _, direct := range directs {
				px := tmp.x + direct[0]
				py := tmp.y + direct[1]
				if walk(px, py) {
					queue = append(queue, point{px, py})
				}
			}
			queue = queue[1:]
		}
		ret++
	}

	return ret
}

```