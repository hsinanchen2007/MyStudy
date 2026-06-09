
```go []
func gameOfLife(board [][]int) {
	lenX := len(board)
	lenY := len(board[0])
	var dir = [8][2]int{
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0},
		{1, 1},
		{1, -1},
		{-1, 1},
		{-1, -1},
	}
	for k1, v1 := range board {
		for k2, v2 := range v1 {
			sum := 0
			for _, vdir := range dir {
				x := k1 + vdir[0]
				y := k2 + vdir[1]
				if x >= 0 && x < lenX && y >= 0 && y < lenY {
					sum += board[x][y] & 1
				}
			}
			v := v2 & 1
			if sum == 3 {
				board[k1][k2] |= 1 << 1
			} else if sum == 2 {
				board[k1][k2] |= v << 1
			} else {
				board[k1][k2] |= 0 << 1
			}
		}
	}
	for k1, v1 := range board {
		for k2 := range v1 {
			board[k1][k2] >>= 1
		}
	}
}
```
