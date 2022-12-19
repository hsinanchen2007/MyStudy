### 解题思路
此处撰写解题思路

### 代码

```golang

func wallsAndGates(rooms [][]int) {
	r := len(rooms)
	if r == 0 {
		return
	}
	c := len(rooms[0])

	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if rooms[i][j] == 0 {
				bfs(rooms, i, j, r, c)
				//dfs(rooms, i, j, r, c, 0)
			}
		}
	}
}

func bfs(rooms [][]int, i, j, r, c int) {
	queue := list.New()
	queue.PushBack([]int{i, j})
	for queue.Len() > 0 {
		elem := queue.Front()
		queue.Remove(elem)
		x, y := elem.Value.([]int)[0], elem.Value.([]int)[1]

		for _, direcory := range [][]int{{0, 1}, {0, -1}, {-1, 0}, {1, 0}} {
			nx, ny := x+direcory[0], y+direcory[1]
			if nx < 0 || nx >= r || ny < 0 || ny >= c || rooms[nx][ny] <= rooms[x][y]+1 {
				continue
			}
			rooms[nx][ny] = rooms[x][y] + 1
			queue.PushBack([]int{nx, ny})
		}

	}
}


func dfs(rooms [][]int, i, j, r, c, distance int) {
	if i < 0 || i >= r || j < 0 || j >= c || rooms[i][j] < distance {
		return
	}
	rooms[i][j] = distance

	if j+1 < c && rooms[i][j+1] != -1 {
		dfs(rooms, i, j+1, r, c, distance+1)
	}

	if j-1 >= 0 && rooms[i][j-1] != -1 {
		dfs(rooms, i, j-1, r, c, distance+1)
	}
	if i+1 < r && rooms[i+1][j] != -1 {
		dfs(rooms, i+1, j, r, c, distance+1)
	}

	if i-1 >= 0 && rooms[i-1][j] != -1 {
		dfs(rooms, i-1, j, r, c, distance+1)
	}
}

```