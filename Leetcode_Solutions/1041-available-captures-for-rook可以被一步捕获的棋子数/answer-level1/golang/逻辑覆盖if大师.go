### 解题思路
找到R的坐标，在定义上下左右四个能吃到p的变量，脑补是否会被B挡到做出相应的处理
### 代码

```golang
func numRookCaptures(board [][]byte) int {
	var RLocI, RLocJ, resultJUp, resultJDown, resultILeft, resultIRight int
	for i := range board {
		for j := range board[i] {
			//fmt.Println(string(board[i][j]))
			if string(board[i][j]) == "R" {
				RLocI, RLocJ = i, j
				break
			}
		}
		if RLocI != 0 || RLocJ != 0 {
			break
		}
	}
	downFlag := false
	rightFlag := false
	for i := range board {
		for j := range board[i] {
			if i < RLocI && string(board[i][j]) == "p" && j == RLocJ && resultJUp == 0 {
				resultJUp ++
			} else if i < RLocI && resultJUp > 0 && j == RLocJ && string(board[i][j]) == "B" {
				resultJUp --
			} else if i > RLocI && string(board[i][j]) == "p" && j == RLocJ && resultJDown <= 0 && !downFlag {
				resultJDown ++
			} else if i > RLocI && resultJDown == 0 && j == RLocJ && string(board[i][j]) == "B" {
				resultJDown --
				downFlag = true
			} else if j < RLocJ && string(board[i][j]) == "p" && i == RLocI && resultILeft == 0 {
				resultILeft ++
			} else if j < RLocJ && resultILeft > 0 && i == RLocI && string(board[i][j]) == "B" {
				resultILeft --
			} else if j > RLocJ && string(board[i][j]) == "p" && i == RLocI && resultIRight <= 0 && !rightFlag {
				resultIRight ++
			} else if j > RLocJ && resultIRight == 0 && i == RLocI && string(board[i][j]) == "B" {
				resultIRight --
				rightFlag = true
			}
		}
	}
	fmt.Println(resultJUp, resultJDown, resultILeft, resultIRight)
	if resultJDown < 0 {
		resultJDown = 0
	}
	if resultIRight < 0 {
		resultIRight = 0
	}
	return resultJUp + resultJDown + resultILeft + resultIRight
}


```