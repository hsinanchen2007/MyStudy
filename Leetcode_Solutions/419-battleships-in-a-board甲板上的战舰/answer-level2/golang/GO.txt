### 解题思路
此处撰写解题思路

### 代码

```golang
func countBattleships(board [][]byte) int {
    x := len(board)
    y := len(board[0])

    res := 0

    for i:=0; i<x; i++ {
        for j:=0; j<y; j++ {
            if board[i][j]=='.' || (i>0 && board[i-1][j]=='X') || (j>0 && board[i][j-1]=='X') {
                continue
            }
            res++
        }
    }

    return res
}
```