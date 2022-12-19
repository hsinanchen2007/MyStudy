比较基本的搜索，考虑清楚什么情况下是false，什么情况下是true就可以

```
func exist(board [][]byte, word string) bool {
    if len(board) == 0 || len(board[0]) == 0 {
        return false
    }
    
    rows := len(board)
    columns := len(board[0])
    
    m := make([][]bool, rows)
    for i := 0; i < rows; i++ {
        m[i] = make([]bool, columns)
    }
    for i := 0; i < rows; i++ {
        for j := 0; j < columns; j++ {
            res := dfs(i, j, board, m, word, 0)    
            if res == true {
                return true
            }
        }
    }
    
    return false
}

func dfs(row int, column int, board [][]byte, m [][]bool, word string, num int) bool {
    if row < 0 || row >= len(board) || column < 0 || column >= len(board[0]) { // 超出边界，false
        return false
    } else if m[row][column] { // 这个点已经走过，不能再走，false
        return false
    } else if board[row][column] != word[num] { // 字符不匹配，false
        return false
    } else if num == len(word) - 1 { // 字符匹配而且已经是最后一个字符，说明有这个条路
       return true
    }
    
    move := [4][2]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
    m[row][column] = true
    for i := 0; i < len(move); i++ {
        res := dfs(row + move[i][0], column + move[i][1], board, m, word, num + 1)
		if res == true {
			return true
		}
    }
    m[row][column] = false // 回溯，如果这个点不符合，应该认为这个点没走过，应该还有其他路可能会到达这个点
    return false
}
```
