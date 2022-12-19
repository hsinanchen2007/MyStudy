dfs 相对于 bfs 来说不需要额外的队列存储，但其实这道题是归属于`栈&队列`章节的，还是建议用 bfs 实现一遍。

这道题解法注意点其实就几个：
- 不能撞墙
- 步数覆盖（从每一个门开始 dfs 求得的步数对其它门来说不一定最小）

### dfs 版本
```go
func wallsAndGates(rooms [][]int) {
	if len(rooms) == 0 || len(rooms[0]) == 0 {
		return
	}

	m, n := len(rooms), len(rooms[0])
	var dfs func(int, int, int)
	dfs = func(i, j, step int) {
		// 如果撞墙或已经访问的房间距离前一个门的步数小于距离当前门的步数
		if i < 0 || i >= m || j < 0 || j >= n || rooms[i][j] < step {
			return
		}

		rooms[i][j] = step
		// 上
		dfs(i-1, j, step+1)
		// 下
		dfs(i+1, j, step+1)
		// 左
		dfs(i, j-1, step+1)
		// 右
		dfs(i, j+1, step+1)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if rooms[i][j] == 0 {
				// 初始门相对自己距离是 0
				dfs(i, j, 0)
			}
		}
	}
}
```

### bfs 版本
官方实现的 bfs 版本明显有 bug，没有考虑存在多个门的情况

```go
func wallsAndGates(rooms [][]int) {
	if len(rooms) == 0 || len(rooms[0]) == 0 {
		return
	}

	DIRECTIONS := [4][2]int{
		[2]int{-1, 0},
		[2]int{1, 0},
		[2]int{0, -1},
		[2]int{0, 1},
	}

	rLen, cLen := len(rooms), len(rooms[0])
	var gates [][2]int
	for i := 0; i < rLen; i++ {
		for j := 0; j < cLen; j++ {
			if rooms[i][j] == 0 {
				gates = append(gates, [2]int{i, j})
			}
		}
	}

	for _, gate := range gates {
		queue := [][2]int{gate}
		visited := make(map[string]bool)
		for len(queue) != 0 {
			row, col := queue[0][0], queue[0][1]
			queue = queue[1:]

			for _, direct := range DIRECTIONS {
				r, c := row+direct[0], col+direct[1]
				// 如果撞墙或者访问下一个房间的步数小于等于当前房间步数+1（可能是撞墙了、碰到下一个门、折返了）
				if r < 0 || r >= rLen || c < 0 || c >= cLen || rooms[r][c] <= rooms[row][col]+1 {
					continue
				}

				rooms[r][c] = rooms[row][col] + 1
				queue = append(queue, [2]int{r, c})
			}
		}
	}
}

```
