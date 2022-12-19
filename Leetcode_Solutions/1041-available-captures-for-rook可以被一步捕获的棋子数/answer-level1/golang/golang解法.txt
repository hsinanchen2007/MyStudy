### 解题思路
...

### 代码

```golang
func numRookCaptures(board [][]byte) int {
    boardLength := 8
    var row, col, ret int
    for i:=0;i<boardLength;i++{
        flag := false
        for j:=0;j<boardLength;j++{
            if board[i][j] == 'R' {
                row = i
                col = j
                flag = true
                break
            }
        }
        if flag {
            break
        }
    }
    for i:=col+1;i<boardLength;i++{
        if board[row][i] == 'p' {
            ret++
            break
        } else if board[row][i] == 'B' {
            break
        }
    }
    for i:=col-1;i>=0;i--{
        if board[row][i] == 'p' {
            ret++
            break
        } else if board[row][i] == 'B' {
            break
        }
    }
    for i:=row+1;i<boardLength;i++{
        if board[i][col] == 'p' {
            ret++
            break
        } else if board[i][col] == 'B' {
            break
        }
    }    
    for i:=row-1;i>=0;i--{
        if board[i][col] == 'p' {
            ret++
            break
        } else if board[i][col] == 'B' {
            break
        }
    }

    return ret
}
```