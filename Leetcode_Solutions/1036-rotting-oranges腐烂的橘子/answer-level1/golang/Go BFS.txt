### 解题思路

使用广度优先搜索 BFS 的解题思想.
首先遍历 grid, 将所有腐烂的橘子都添加至队列中, 并计算新鲜橘子的数量.
然后判断队列长度是否大于 0, 如果小于 0, 则直接返回 -1, 因为该 grid 中不存在腐烂橘子; 如果新鲜橘子的数量为 0, 则表示已满足条件, 则直接返回 0.
最后进行 BFS, 每次从腐烂橘子队列中取出 `curLen := len(rottenQueue)` 个数据, 并各自进行BFS, 并将遇到的新鲜橘子修改为腐烂橘子, 添加至队列中.
直至队列元素为 0 或者新鲜橘子数量小于等于 0.

### 代码

```golang
func orangesRotting(grid [][]int) int {
	const (
		Fresh int = 1
		Rotten int = 2
	)
	var freshNum int
	n, m := len(grid), len(grid[0])
	rottenQueue := make([][]int, 0)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == Rotten {
				rottenQueue = append(rottenQueue, []int{i, j})
			}
			if grid[i][j] == Fresh {
				freshNum++
			}
		}
	}
	if freshNum == 0 {
		return 0
	}
	if len(rottenQueue) == 0 {
		return -1
	}
	t := 0

	for len(rottenQueue) != 0 && freshNum > 0 {
		curLen := len(rottenQueue)
		for k := 0; k < curLen; k++ {
			i, j := rottenQueue[k][0], rottenQueue[k][1]
			if i > 0 && grid[i-1][j] == Fresh {
				rottenQueue = append(rottenQueue, []int{i-1, j})
				grid[i-1][j] = Rotten
				freshNum--
			}
			if i < n-1 && grid[i+1][j] == Fresh {
				rottenQueue = append(rottenQueue, []int{i+1, j})
				grid[i+1][j] = Rotten
				freshNum--
			}
			if j > 0 && grid[i][j-1] == Fresh {
				rottenQueue = append(rottenQueue, []int{i, j-1})
				grid[i][j-1] = Rotten
				freshNum--
			}
			if j < m-1 && grid[i][j+1] == Fresh {
				rottenQueue = append(rottenQueue, []int{i, j+1})
				grid[i][j+1] = Rotten
				freshNum--
			}
		}
		rottenQueue = rottenQueue[curLen:]
		t++
	}
	if freshNum != 0 {
		return -1
	}
	return t
}
```