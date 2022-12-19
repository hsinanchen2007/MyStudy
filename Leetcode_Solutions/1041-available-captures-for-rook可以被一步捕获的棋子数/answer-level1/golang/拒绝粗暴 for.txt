```go
func numRookCaptures(board [][]byte) int {
	var (
		i, j, curr, currX, currY, rst, rX, rY int
		dx                                    = []int{0, 1, 0, -1}
		dy                                    = []int{1, 0, -1, 0}
	)
	for i = 0; i < 8; i++ {
		for j = 0; j < 8; j++ {
			if board[i][j] == 'R' {
				rX = i
				rY = j
				break
			}
		}
	}
	for i = 0; i < 4; i++ {
		for curr = 0; ; curr++ {
			currX = rX + curr*dx[i]
			currY = rY + curr*dy[i]
			if currX < 0 || currX >= 8 || currY < 0 || currY >= 8 || board[currX][currY] == 'B' {
				break
			}
			if board[currX][currY] == 'p' {
				rst++
				break
			}
		}
	}
	return rst
}

```
