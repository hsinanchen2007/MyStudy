### 解题思路
遍历board上的每个点，尝试构造word，若遇到字母不符合的情况，立即返回。
由于在一次尝试中，一个格子只能访问一次，因此需要一个visit二维数组来记录哪些位置在本次递归中已经访问过。

### 代码
执行用时 :4 ms, 在所有 Go 提交中击败了96.87%的用户
内存消耗 :3.7 MB, 在所有 Go 提交中击败了70.86%的用户
```golang
func exist(board [][]byte, word string) bool {
    visit := make([][]bool, len(board))
    for i := 0; i < len(board); i++ {
        visit[i] = make([]bool, len(board[0]))
    }
    for i:=0; i < len(board); i++ {
        for j :=0; j < len(board[0]); j++{
            if search(board, word, i,j, visit) {
                return true
            }
        }
    }
    return false
}

func search(board [][]byte, word string, i,j int, visit [][]bool) bool {
    if i < 0 || j < 0 || i >= len(board) || j >= len(board[0]) {
        return false
    }
    if visit[i][j] || board[i][j] != word[0]{
        return false
    }
    if len(word) == 1 {
        return board[i][j] == word[0]
    }
    visit[i][j] = true
    result := search(board, word[1:], i+1,j, visit) || search(board, word[1:], i-1,j, visit) || search(board, word[1:], i,j+1, visit) || search(board, word[1:], i,j-1, visit) 
    visit[i][j] = false
    return result
}

```