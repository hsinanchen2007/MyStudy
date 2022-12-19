### 解题思路
见甜姨

### 代码

```golang
func gameOfLife(board [][]int) {
	for i := range board {
		for j := range board[i] {
			count := 0
			if i+1 < len(board) {
				count += board[i+1][j] & 1
			}
			if j+1 < len(board[i]) {
				count += board[i][j+1] & 1
			}
			if i-1 > -1 {
				count += board[i-1][j] & 1
			}
			if j-1 > -1 {
				count += board[i][j-1] & 1
			}
			if i+1 < len(board) && j+1 < len(board[i]) {
				count += board[i+1][j+1] & 1
			}
			if j+1 < len(board[i]) && i-1 > -1 {
				count += board[i-1][j+1] & 1
			}
			if i-1 > -1 && j-1 > -1 {
				count += board[i-1][j-1] & 1
			}
			if j-1 > -1 && i+1 < len(board) {
				count += board[i+1][j-1] & 1
			}
			switch count {
			case 0, 1:
				board[i][j] &= 1
			case 2:
				board[i][j] |= board[i][j] << 1
			case 3:
				board[i][j] |= 1 << 1
			default:
				board[i][j] &= 1
			}
		}
	}
	for i := range board {
		for j := range board[i] {
			board[i][j] = (board[i][j] >> 1) & 1
		}
	}
}

```