### 解题思路
我为go代言

### 代码

```golang
func numRookCaptures(board [][]byte) int {
	num := 0
	stop := make(chan int)
	r := [2]int{}
	for i := 0; i < len(board); i++ {
		go find(i, &r, board[i], stop)
	}
	<-stop
	raw := r[0]  //横
	hang := r[1] //竖
	for i := raw; i > 0; i-- {
		if board[i][hang] == '.' {
			continue
		}
		if board[i][hang] == 'p' {
			num++
			break
		}
		if board[i][hang] == 'B' {
			break
		}

	}
	for i := raw; i < 8; i++ {
		if board[i][hang] == '.' {
			continue
		}
		if board[i][hang] == 'p' {
			num++
			break
		}
		if board[i][hang] == 'B' {
			break
		}
	}
	for i := hang; i > 0; i-- {
		if board[raw][i] == '.' {
			continue
		}
		if board[raw][i] == 'p' {
			num++
			break
		}
		if board[raw][i] == 'B' {
			break
		}
	}
	for i := hang; i < 8; i++ {
		if board[raw][i] == '.' {
			continue
		}
		if board[raw][i] == 'p' {
			num++
			break
		}
		if board[raw][i] == 'B' {
			break
		}
	}
	return num
}

func find(x int, r *[2]int, array []byte, stop chan int) {
	for i := 0; i < 8; i++ {
		if array[i] == 'R' {
			r[0] = x
			r[1] = i
			stop <- 1
			return
		}
	}
}

```