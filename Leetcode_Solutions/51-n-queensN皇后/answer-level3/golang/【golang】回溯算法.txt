![image.png](https://pic.leetcode-cn.com/d4728677802a3fe0c4dda80eff5c3d214b15a09da7c7bad78450ec31675123a1-image.png)


```
func solveNQueens(n int) [][]string {
	var res [][]string
	nQueen := make([][]rune, n)
	for i := range nQueen {
		nQueen[i] = make([]rune, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			nQueen[i][j] = '.'
		}
	}
	solveNQueensDFS(&res, nQueen, 0, n)
	return res
}

func solveNQueensDFS(res *[][]string, nQueen [][]rune, row, n int) {
	if row == n {
		tmp := make([]string, n)
		for i := range nQueen {
			tmp[i] = string(nQueen[i])
		}
		*res = append(*res, tmp)
	}
	for col := 0; col < n; col++ {
		if solveNQueensIsValid(nQueen, row, col, n) {
			nQueen[row][col] = 'Q'
			solveNQueensDFS(res, nQueen, row+1, n)
			nQueen[row][col] = '.'
		}
	}
}

func solveNQueensIsValid(nQueen [][]rune, row, col, n int) bool {
	for i := 0; i < row; i++ {
		if nQueen[i][col] == 'Q' {
			return false
		}
	}
	for i, j := row-1, col-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if nQueen[i][j] == 'Q' {
			return false
		}
	}
	for i, j := row-1, col+1; i >= 0 && j < n; i, j = i-1, j+1 {
		if nQueen[i][j] == 'Q' {
			return false
		}
	}
	return true
}
```