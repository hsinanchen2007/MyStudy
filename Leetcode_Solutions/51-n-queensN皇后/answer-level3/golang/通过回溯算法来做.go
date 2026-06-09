### 解题思路

回溯算法框架
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

### 代码

```golang

func solveNQueens(n int) [][]string {
	board := make([][]string, n)
	for i := 0; i < n; i++ {
		a := make([]string, n)
		for j := 0; j < n; j++ {
			a[j] = "."
		}
		board[i] = a
	}

	var result [][]string
	backtrack(board, &result, 0)
	return result
}
func backtrack(board [][]string, result *[][]string, row int) {
	if row == len(board) {
		//fmt.Println("result ",board)
		b := getResult(board)
		*result = append(*result, b)
		return
	}
	for i := 0; i < len(board); i++ {
		if isValid(board, row, i) {
		//	fmt.Println("valid ",board)
			board[row][i] = "Q"
			backtrack(board, result, row+1)
			board[row][i] = "."
		}
	}
}
func getResult(board [][]string) []string {
	var result []string
	for i := 0; i < len(board); i++ {
		var a string
		for j := 0; j < len(board); j++ {
			a = a + board[i][j]
		}
		result = append(result, a)
	}
	return result
}
func isValid(board [][]string, row, y int) bool {
	n := len(board)
	// 左上方
	i := row - 1
	j := y - 1
	for i >= 0 && j >= 0 {
		if board[i][j] == "Q" {
			return false
		}
		i--
		j--
	}

	// 右上方
	i = row - 1
	j = y + 1
	for i >= 0 && j < n {
		if board[i][j] == "Q" {
			return false
		}
		i--
		j++
	}
	// 同一列
	i = row-1
	j = y
	for i >= 0 {
		if board[i][j] == "Q" {
			return false
		}
		i--
	}
	return true
}

```