### 解题思路
将已访问过的标记

### 代码

```golang
func exist(board [][]byte, word string) bool {
	visited := make([][]bool, len(board))
	for i := 0; i < len(board); i++ {
		visited[i] = make([]bool, len(board[0]))
	}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if hasPathCore(board, i, j, word, 0, visited) {
				return true
			}
		}
	}

	return false
}

func hasPathCore(board [][]byte, i int, j int, word string, length int, visited [][]bool) bool {
	if length == len(word) {
		return true
	}

	hasPath := false
	if i >= 0 && i < len(board) && j >= 0 && j < len(board[0]) && board[i][j] == word[length] && !visited[i][j] {
		length++
		visited[i][j] = true
		hasPath = hasPathCore(board, i, j-1, word, length, visited) ||
			hasPathCore(board, i-1, j, word, length, visited) ||
			hasPathCore(board, i, j+1, word, length, visited) ||
			hasPathCore(board, i+1, j, word, length, visited)
		if !hasPath {
			length--
			visited[i][j] = false
		}
	}
	return  hasPath
}
```