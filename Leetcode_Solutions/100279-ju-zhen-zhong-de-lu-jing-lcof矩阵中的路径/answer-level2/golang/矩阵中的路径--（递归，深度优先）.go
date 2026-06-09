### 解题思路
此处撰写解题思路

### 代码

```golang
func exist(board [][]byte, word string) bool {
	// 是否访问过
	visited := make([][]bool, len(board))
	for i := 0; i < len(board); i++ {
		visited[i] = make([]bool, len(board[0]))
	}

	for i1,_:=range board{
		for i2,_:=range board[i1]{
			if board[i1][i2] == word[0] {
				if search(board,visited,i1,i2,0,word) {
					return true
				}
			}
		}
	}

	return false
}

func search(board [][]byte,visited [][]bool,n,m,x int,str string) bool {
	if board[n][m] != str[x] || visited[n][m] {
		return false
	}

	visited[n][m] = true

	if x == len(str)-1 {
		return true
	}

	if n-1 >= 0 && search(board,visited,n-1,m,x+1,str) ||
		n+1 < len(board) && search(board,visited,n+1,m,x+1,str) ||
		m-1 >= 0 && search(board,visited,n,m-1,x+1,str) ||
		m+1 < len(board[0]) && search(board,visited,n,m+1,x+1,str) {
		return true
	}

	visited[n][m] = false
	return false
}
```