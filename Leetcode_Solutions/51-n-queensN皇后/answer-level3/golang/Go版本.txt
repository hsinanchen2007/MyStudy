```
func solveNQueens(n int) [][]string {
	var queues [][]string
	var board = make([][]byte, n)
	for i := 0; i < n; i++ {
		board[i] = make([]byte, n)
		for j := 0; j < n; j++ {
			board[i][j] = '.'
		}
	}
	backTrace(&queues, board, 0, n)
	return queues
}

func backTrace(queues *[][]string, board [][]byte, row, n int) {
	if row == n {
		var tmp []string
		for i := 0; i < n; i++ {
			tmp = append(tmp, string(board[i]))
		}
		*queues = append(*queues, tmp)
		return
	}
	for col := 0; col < len(board); col++ {
		if !isValid(board, row, col) {
			continue
		}
		board[row][col] = 'Q'
		backTrace(queues, board, row+1, n)
		board[row][col] = '.'
	}
}

func isValid(board [][]byte, row, col int) bool {
	for i := 0; i < len(board); i++ {
		if board[i][col] == 'Q' {
			return false
		}
	}
	for i, j := row-1, col+1; i >= 0 && j < len(board); i, j = i-1, j+1 {
		if board[i][j] == 'Q' {
			return false
		}
	}
	for i, j := row-1, col-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if board[i][j] == 'Q' {
			return false
		}
	}
	return true
}
```
