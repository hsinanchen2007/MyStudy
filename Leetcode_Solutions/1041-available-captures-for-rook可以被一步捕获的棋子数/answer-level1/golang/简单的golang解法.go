//车的移动直线，从车的位置出发，可以向四个方向行走，只有遇到自己棋子或敌方棋子才会停止，代码如下：

func NumRookCaptures(board [][]byte) int {
	x,y := searchRoot(board)
	if x==-1 && y==-1 {
		return 0
	}
	//以初始位置为中心，向四个方向搜查，只有遇到棋子才停止
	//并把captureNum返回值加上
	sum := 0
	for i:=x-1; i>=0; i-- {
		n := captureNum(board[i][y])
		if n != -1 {
			sum += n
			break
		}
	}
	for i:=x+1; i<len(board); i++ {
		n := captureNum(board[i][y])
		if n != -1 {
			sum += n
			break
		}
	}
	for j:=y-1; j>=0; j-- {
		n := captureNum(board[x][j])
		if n != -1 {
			sum += n
			break
		}
	}
	for j:=y+1; j<len(board[0]); j++ {
		n := captureNum(board[x][j])
		if n != -1 {
			sum += n
			break
		}
	}
	return sum
}

//搜素初始位置
func searchRoot(board [][]byte) (x int, y int) {
	for i:=0; i<len(board); i++ {
		for j:=0; j<len(board[0]); j++ {
			if board[i][j] == 'R' {
				return i, j
			}
		}
	}
	return -1, -1
}
//判断引动到当前位置，是否捕捉到敌方棋子
//遇到自家棋子返回0
//敌方棋子返回1
//都不是返回-1，表示继续寻找
func captureNum(n byte) int  {
	switch n {
	case 'B':
		return 0
	case 'p':
		return 1
	default:
		return -1

	}
}