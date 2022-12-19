### 解题思路
```执行用时 :
4 ms
, 在所有 golang 提交中击败了
98.50%
的用户
内存消耗 :
3.2 MB
, 在所有 golang 提交中击败了
100.00%
的用户```

### 代码

```golang
func solveNQueens(n int) [][]string {
	var res [][]string
	// 生成一个n x n的二维数组，并赋值"."
	board := make([][]rune, n)
	for i := 0; i < n; i++ {
		item := make([]rune, n)
		for j := 0; j < n; j++ {
			item[j] = '.'
		}
		board[i] = item
	}
	backtrack(board, &res, n, 0)
	return res
}

func backtrack(board [][]rune, res *[][]string, n, row int) {
	// 结束条件
	if row == len(board) {
		var arr []string
		for _, v := range board {
			arr = append(arr, string(v))
		}
		// fmt.Println(arr)
		*res = append(*res, arr)
		return
	}
	// 列循环
	for col := 0; col < len(board); col++ {
		// 去除不合法的数据
		if isOk(board, row, col) {
			// 做选择
			board[row][col] = 'Q'
			// 进入下一决策
			backtrack(board, res, n - 1, row + 1)
			// 撤销选择
			board[row][col] = '.'
		}
	}
}

func isOk(board [][]rune, row int, col int) bool {
	// 查询上方数据
	for i := 0; i < row; i++ {
		if board[i][col] == 'Q' {
			return false
		}
	}

	// 查询右上角
	for i, j := row-1, col+1; i >= 0 && j < len(board); {
		if board[i][j] == 'Q' {
			return false
		}
		i--
		j++
	}

	// 查询左上角
	for i, j := row-1, col-1; i >= 0 && j >= 0; {
		if board[i][j] == 'Q' {
			return false
		}
		i--
		j--
	}
	return true
}

```