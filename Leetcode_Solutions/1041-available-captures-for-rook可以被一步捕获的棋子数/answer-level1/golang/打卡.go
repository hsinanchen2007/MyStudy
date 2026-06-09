### 解题思路
循环找四个方向

### 代码

```golang
func numRookCaptures(board [][]byte) int {
	var x, y, sum int
	for i := 0; i < 8; i++ {
		for j := 0; j < 8; j++ {
			if board[i][j] == byte('R') {
				x, y = i, j
				break
			}
		}
	}

	//北
	for i := y; i >= 0; i-- {
		if board[x][i] == byte('p') {
			sum++
			break
		}

		if board[x][i] == byte('B') {
			break
		}
	}

	//东
	for i := x; i < 8; i++ {
		if board[i][y] == byte('p') {
			sum++
			break
		}

		if board[i][y] == byte('B') {
			break
		}
	}
	//西
	for i := x - 1; i >= 0; i-- {
		if board[i][y] == byte('p') {
			sum++
			break
		}

		if board[i][y] == byte('B') {
			break
		}
	}

	//南
	for i := y + 1; i < 8; i++ {
		if board[x][i] == byte('p') {
			sum++
			break
		}

		if board[x][i] == byte('B') {
			break
		}
	}
	return sum

}

```