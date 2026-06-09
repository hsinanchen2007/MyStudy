```
func orangesRotting(grid [][]int) int {
	m  := len(grid)
	n  := len(grid[0])
	ans := 0
	// 判断该点是否已经进过队列
	used := make([][]bool, m)
	for i := 0; i < m; i++ {
		used[i] = make([]bool, n)
	}
	dx := []int{-1, 0, 1, 0 }
	dy := []int{0,  1, 0, -1}
	cnt := 0
	q  := &Queue{}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 2 {
				q.offer(Node{
					x   : i,
					y   : j,
					min : 0,
				})
				used[i][j] = true
			} else if grid[i][j] == 1 {
				cnt++
			}
		}
	}

	for len(*q) != 0 {
		node := q.poll()
		ans = node.min
		for i := 0; i < 4; i++ {
			x := node.x + dx[i]
			y := node.y + dy[i]
			if x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || used[x][y] {
				continue
			}

			// 此时grid[x][y]只可能是1
			used[x][y] = true
			q.offer(Node{
				x : x,
				y : y,
				min : node.min + 1,
			})
			cnt--
			if cnt == 0 {
				break
			}

		}
	}
	if cnt == 0 {
		return ans
	}
	return -1
}

type Node struct {
	x   int
	y   int
	min int
}

type Queue []Node
func (q *Queue) offer(n Node) {
	*q = append(*q, n)
}
func (q *Queue) poll() Node {
	r := (*q)[0]
	*q = (*q)[1:]
	return r
}
```
