### 解题思路
0 ms
, 在所有 golang 提交中击败了
100.00%
的用户

### 代码

```golang
func totalNQueens(n int) int {
    res := 0 
    // 生成一个n x n的数组
    board := make([][]rune, n)
    for i := 0; i<n; i++ {
        item := make([]rune, n)
        for k, _ := range item {
            item[k] = '.'
        }
        board[i] = item
    }

    backtrack(board, &res, 0)
    return res
}

func backtrack(board [][]rune, res *int, row int) {
    // 退出条件
    if row == len(board) {
        *res++
        return
    }

    // N叉树遍历
    for col := 0; col < len(board); col ++ {
        // 排除不合法的数据
        if isOk(board, row, col) {
            // 做选择
            board[row][col] = 'Q'
            // 进入下一层
            backtrack(board, res, row + 1)
            // 撤销选择
            board[row][col] = '.'
        }
    }
}

func isOk(board [][]rune, row, col int) bool {

    // 检查上方数据
    for i := 0; i<row; i++ {
        if board[i][col] == 'Q' {
            return false
        }
    }

    // 检查左上方数据
    for i, j := row - 1, col - 1; i >= 0 && j >= 0; {
        if board[i][j] == 'Q' {
            return false
        }
        i--
        j--
    }

    // 检查右上方
    for i, j := row - 1, col + 1; i >= 0 && j < len(board); {
        if board[i][j] == 'Q' {
            return false
        }
        i--
        j++
    }
    return true
}
```