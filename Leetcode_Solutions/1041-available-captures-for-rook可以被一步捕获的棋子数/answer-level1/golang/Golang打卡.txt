### 解题思路
此处撰写解题思路

### 代码

```golang
func numRookCaptures(board [][]byte) int {
    var (
        helper func(i,j int)
        count = 0
    )
    helper = func(i,j int) {
        var (
            up = i
            down = i
            left = j
            right = j
        )
        for up-1 >= 0 && (board[up-1][j] != 'B' && board[up-1][j] != 'p') {
            up --
        }
        if up-1 >= 0 && board[up-1][j] == 'p' {
            count ++
        }
        for down+1 < len(board) && (board[down+1][j] != 'B' && board[down+1][j] != 'p') {
            down ++
        }
        if down+1 < len(board) && board[down+1][j] == 'p' {
            count ++
        }
        for left-1 >= 0 && (board[i][left-1] != 'B' && board[i][left-1] != 'p') {
            left --
        }
        if left-1 >= 0 && board[i][left-1] == 'p' {
            count ++
        }
        for right+1 < len(board[0]) && (board[i][right+1] != 'B' && board[i][right+1] != 'p') {
            right ++
        }
        if right+1 < len(board[0]) && board[i][right+1] == 'p' {
            count ++
        }
    }
    for i := 0; i < len(board); i ++ {
        for j := 0; j < len(board[0]); j ++ {
            if board[i][j] == 'R' {
                helper(i,j)
                return count
            }
        }
    }
    return -1
}
```