### 解题思路

很简单，沿着上下左右四个方向扫描就行了。

### 代码

```golang
func numRookCaptures(board [][]byte) int {
	l,r := 0,0
	res := 0
	for i := 0;i < len(board);i++ {
		for j := 0;j < len(board[0]);j++ {
			if board[i][j] == 'R' {
				l,r = i,j
			}
		}
	}
	up,down,left,right := l,l,r,r
	for up >= 0 {
		if board[up][r] == 'B' {
			break
		}
		if board[up][r] == 'p' {
			res++
			break
		}
        up--
	}
	for down <= len(board) - 1 {
		if board[down][r] == 'B' {
			break
		}
		if board[down][r] == 'p' {
			res++
			break
		}
        down++
	}
	for left >= 0 {
		if board[l][left] == 'B' {
			break
		}
		if board[l][left] == 'p' {
			res++
			break
		}
        left--
	}
	for right <= len(board[0]) - 1 {
		if board[l][right] == 'B' {
			break
		}
		if board[l][right] == 'p' {
			res++
			break
		}
        right++
	}
	return res
}
```