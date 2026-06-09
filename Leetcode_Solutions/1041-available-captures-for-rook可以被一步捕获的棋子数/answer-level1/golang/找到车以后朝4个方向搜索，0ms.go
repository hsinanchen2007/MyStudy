找到车以后朝4个方向搜索，每次搜索都是遇到卒计数然后退出，遇到象直接退出
```
func numRookCaptures(board [][]byte) int {
	var posRow = -1
	var posCol = -1
out:
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[i]); j++ {
			if board[i][j] == 'R' {
				posRow = i
				posCol = j
				break out
			}
		}
	}
	var sum = 0
	//left
	for j := posCol - 1; j >= 0; j-- {
		if board[posRow][j] == 'p' {
			sum++
			break
		} else if board[posRow][j] == 'B' {
			break
		}
	}
	//right
	for j := posCol + 1; j < len(board[0]); j++ {
		if board[posRow][j] == 'p' {
			sum++
			break
		} else if board[posRow][j] == 'B' {
			break
		}
	}
	//up
	for i := posRow - 1; i >= 0; i-- {
		if board[i][posCol] == 'p' {
			sum++
			break
		} else if board[i][posCol] == 'B' {
			break
		}
	}
	//down
	for i := posRow + 1; i < len(board); i++ {
		if board[i][posCol] == 'p' {
			sum++
			break
		} else if board[i][posCol] == 'B' {
			break
		}
	}
	return sum
}

```
