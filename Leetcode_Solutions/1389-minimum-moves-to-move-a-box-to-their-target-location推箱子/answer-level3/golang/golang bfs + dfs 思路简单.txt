广度搜索箱子的时候，每次判断人是否能走到对立面

```go
var (
	rg   = [][]int{[]int{-1, 0}, []int{1, 0}, []int{0, 1}, []int{0, -1}}
	n, m int
)

func minPushBox(grid [][]byte) int {
	if len(grid) == 0 {
		return -1
	}
	var man, box [2]int
	n, m = len(grid), len(grid[0])
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			switch grid[i][j] {
			case 'S':
				man = [2]int{i, j}
			case 'B':
				box = [2]int{i, j}
			}
		}
	}
	return bfs(grid, man, box)
}

type Node struct {
	x, y   int
	step   int
	manPos [2]int
}

func bfs(grid [][]byte, man, box [2]int) int {
	stack := make([]Node, 10000)
	visited := make(map[[4]int]bool)
	start, end := 0, 0
	stack[start] = Node{
		x:      box[0],
		y:      box[1],
		manPos: man,
	}
	for start <= end {
		x, y, s := stack[start].x, stack[start].y, stack[start].step
		if grid[x][y] == 'T' {
			return s
		}
		manX, manY := stack[start].manPos[0], stack[start].manPos[1]
		start++
		for _, r := range rg {
			x1, y1 := x+r[0], y+r[1]
			if x1 < 0 || x1 >= n || y1 < 0 || y1 >= m {
				continue
			}
			if grid[x1][y1] == '#' {
				continue
			}
			x2, y2 := x-r[0], y-r[1]
			if x2 < 0 || x2 >= n || y2 < 0 || y2 >= m {
				continue
			}
			if visited[[4]int{x1, y1, x2, y2}] {
				continue
			}
			if dfs(grid, map[[2]int]bool{[2]int{x, y}: true}, manX, manY, [2]int{x, y}, [2]int{x2, y2}) {
				if grid[x1][y1] == 'T' {
					return s + 1
				}
				end++
				stack[end] = Node{
					x:      x1,
					y:      y1,
					step:   s + 1,
					manPos: [2]int{x2, y2},
				}
				visited[[4]int{x1, y1, x2, y2}] = true
			}
		}
	}
	return -1
}

func dfs(grid [][]byte, visited map[[2]int]bool, x, y int, box, target [2]int) bool {
	visited[[2]int{x, y}] = true
	for _, r := range rg {
		x1, y1 := x+r[0], y+r[1]
		if x1 < 0 || x1 >= n || y1 < 0 || y1 >= m {
			continue
		}
		if visited[[2]int{x1, y1}] || grid[x1][y1] == '#' || (x1 == box[0] && y1 == box[1]) {
			continue
		}
		if x1 == target[0] && y1 == target[1] {
			return true
		}
		if dfs(grid, visited, x1, y1, box, target) {
			return true
		}
	}
	return false
}

```
