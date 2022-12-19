## 解题思路
深度优先搜索和广度优先搜索，可通过visit数组维护访问过的记录，此题中可利用原数据grid 将1设为0表示访问过
广度优先搜索维护一个队列，每次从队列中取出来处理，将节点的四周加入到队列中

```go

func numIslands(grid [][]byte) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	var res int
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == '1' {
				res++
				BFS(grid, i, j)     // 广度优先搜索
                //DFS(grid, i, j)      //深度优先搜索
			}
		}
	}
	return res
}
func DFS(grid [][]byte, x, y int) {
	if x < 0 || y < 0 || x > len(grid) || y > len(grid[0])-1 {
		return
	}
	if grid[x][y] == '1' {
		grid[x][y] = '0'
	} else {
		return
	}
	// 上下左右

	DFS(grid, x-1, y)

	DFS(grid, x+1, y)
	DFS(grid, x, y-1)
	DFS(grid, x, y+1)
}

type Node struct {
	x, y int
}

func BFS(grid [][]byte, x, y int) {

	var queue []Node
	queue = append(queue, Node{x, y})
	for len(queue) != 0 {
		// pop
		n := queue[0]
		queue = queue[1:]
		if grid[n.x][n.y] == '1' {
			grid[n.x][n.y] = '0'
		}
		if x-1 > 0 {
			queue = append(queue, Node{x - 1, y})
		}
		if x+1 < len(grid) {
			queue = append(queue, Node{x + 1, y})
		}
		if y-1 > 0 {
			queue = append(queue, Node{x, y - 1})
		}
		if y+1 < len(grid) {
			queue = append(queue, Node{x, y + 1})
		}
	}
}

```