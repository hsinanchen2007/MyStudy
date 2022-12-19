```
// dfs
func exist(board [][]byte, word string) bool {
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if helper(i, j, board, word, 0) {
				return true
			}
		}
	}
	return false
}

func helper(row, col int, board [][]byte, word string, pos int) bool {
	if pos == len(word) {
		return true
	}
	// check position
	if row < 0 || col < 0 || row == len(board) || col == len(board[0]) {
		return false
	}
	// check current character
	if board[row][col] != word[pos] {
		return false
	}
	// next character
	board[row][col] ^= byte(128)
	if helper(row, col+1, board, word, pos+1) ||
		helper(row, col-1, board, word, pos+1) ||
		helper(row+1, col, board, word, pos+1) ||
		helper(row-1, col, board, word, pos+1) {
		return true
	}
	board[row][col] ^= byte(128)
	return false
}
```