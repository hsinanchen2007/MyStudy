### 解题思路
此处撰写解题思路

### 代码

```golang
func solve(board [][]byte) {
	l := len(board)
	if l == 0 {
		return
	}
	count := len(board[0])
//只是单纯的记住是否已经算过加快运行速度
	datas := make([][]bool, l)
	for i := 0; i < l; i++ {
		datas[i] = make([]bool, count)
	}
//只需要计算边界上的'O'然后由边界上的'O'往里推进
	for i := 0; i < l; i++ {
		for j := 0; j < count; j++ {
			if (i == 0 || j == 0 || i == l-1 || j == count-1) && board[i][j] == 'O' {
				search(i, j, l, count, board,datas)
			}

		}
	}
	for i, _ := range board {
		for j := 0; j < count; j++ {
			if board[i][j]!='*' {
				board[i][j] = 'X'
			}else {
				board[i][j] = 'O'
			}
		}
	}
}

func search(x, y, l, count int, board [][]byte,datas [][]bool){
	if x < 0 || y < 0 || x >= l || y >= count || board[x][y] == '*' {
		return
	}
	if datas[x][y]{
		return
	}
	if board[x][y] == 'O' {
		board[x][y] = '*'
		search(x+1, y, l, count, board,datas)
		if x+1<l{
			datas[x+1][y]=true
		}
		search(x-1, y, l, count, board,datas)
		if x-1>=0{
			datas[x-1][y]=true
		}
		search(x, y+1, l, count, board,datas)
		if y+1<count{
			datas[x][y+1]=true
		}
		search(x, y-1, l, count, board,datas)
		if y-1>=0{
			datas[x][y-1]=true
		}
	}
	datas[x][y]=true
	return
}

```