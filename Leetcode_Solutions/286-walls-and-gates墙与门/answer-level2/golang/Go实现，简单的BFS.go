我们使用go语言的channel发挥队列的作用。

```go
func wallsAndGates(rooms [][]int)  {
	maxInt := math.MaxInt32
	rowLen := len(rooms)
	if rowLen == 0 {
		return
	}
	colLen := len(rooms[0])
	if colLen == 0 {
		return
	}
	direction := [][]int{
		{1, 0},
		{-1, 0},
		{0, 1},
		{0, -1},
	}

	// 先将所有门遍历出来
	ch := make(chan []int, rowLen * colLen)
    defer close(ch)

	for i:=0; i<rowLen; i++ {
		for j:=0; j<colLen;j++ {
			if rooms[i][j] == 0 {
				ch <- []int{i, j}
			}
		}
	}

	// 开始从门进行BFS
	var door []int
	var a, b int
	for len(ch) > 0 {
		door = <- ch
		for _, v := range direction {
			a = door[0] + v[0]
			b = door[1] + v[1]
			if a < 0 || b < 0 || a >= rowLen || b >= colLen || rooms[a][b] != maxInt {
				continue
			}
			rooms[a][b] = rooms[door[0]][door[1]] + 1
			ch <- []int{a, b}
		}
	}
}
```
