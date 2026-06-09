### 解题思路
打卡

### 代码

```golang
func gameOfLife(board [][]int) {
	height := len(board)
	width := len(board[0])
	flag := [][]int{}
	for i := 0; i < height; i++ {
		tempflag := []int{}
		for j := 0; j < width; j++ {
			if board[i][j] == 1 {
				liveCellCount := checkLiveCell(board, i, j, height, width)
				if liveCellCount == 2 || liveCellCount == 3 {
					tempflag = append(tempflag, 0)
				} else {
					tempflag = append(tempflag, -1)
				}
			} else {
				liveCellCount := checkLiveCell(board, i, j, height, width)
				if liveCellCount == 3 {
					tempflag = append(tempflag, 1)
				} else {
					tempflag = append(tempflag, 0)
				}
			}
		}
		flag = append(flag, tempflag)
	}

	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			board[i][j] += flag[i][j]
		}
	}

}

func checkLiveCell(board [][]int, i int, j int, height int, width int) int {
	liveCellCount := 0
	if i-1 >= 0 {
		if board[i-1][j] == 1 {
			liveCellCount++
		}
	}
	if i+1 < height {
		if board[i+1][j] == 1 {
			liveCellCount++
		}
	}
	if j-1 >= 0 {
		if board[i][j-1] == 1 {
			liveCellCount++
		}
	}
	if j+1 < width {
		if board[i][j+1] == 1 {
			liveCellCount++
		}
	}
	if i-1 >= 0 && j-1 >= 0 {
		if board[i-1][j-1] == 1 {
			liveCellCount++
		}
	}
	if i-1 >= 0 && j+1 < width {
		if board[i-1][j+1] == 1 {
			liveCellCount++
		}
	}
	if i+1 < height && j-1 >= 0 {
		if board[i+1][j-1] == 1 {
			liveCellCount++
		}
	}
	if i+1 < height && j+1 < width {
		if board[i+1][j+1] == 1 {
			liveCellCount++
		}
	}
	return liveCellCount
}
```