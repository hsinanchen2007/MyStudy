``` golang
var dx = []int{0, 1, 1, 1, 0, -1, -1, -1}
var dy = []int{1, 1, 0, -1, -1, -1, 0, 1}

func gameOfLife(board [][]int) {
	n := len(board)
	m := len(board[0])
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			cnt := 0
			for k := 0; k < 8; k++ {
				var x, y = 0, 0
				x = i + dx[k]
				y = j + dy[k]
				if x < 0 || x >= n || y < 0 || y >= m {
					continue
				}
				cnt += board[x][y] & 1
			}
			if board[i][j]&1 > 0 {
				// alive cell
				if cnt >= 2 && cnt <= 3 {
					board[i][j] = 0b11
				}
			} else if cnt == 3 {
				// dead cell, will back to alive
				board[i][j] = 0b10
			}
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			board[i][j] >>= 1
		}
	}
}
```