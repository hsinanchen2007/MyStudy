### 解题思路
![1.PNG](https://pic.leetcode-cn.com/bbc211074714065f962f8fd7fc7aa6717159d3a3e54f4e022922eac08c8020ff-1.PNG)


### 代码

```golang
func numRookCaptures(board [][]byte) int {
    x, y := 0, 0
    for i := 0;i < len(board);i++ {
        for j := 0;j < len(board[i]);j++ {
            if board[i][j] == 'R' {
                x, y = i, j
                i = len(board)
                break
            }
        }
    }
    ans := 0
    for i := x;i >= 0 && board[i][y] != 'B';i-- {
        if board[i][y] == 'p' {
            ans++
            break
        }
    }
    for i := x;i < len(board) && board[i][y] != 'B';i++ {
        if board[i][y] == 'p' {
            ans++
            break
        }
    }
    for i := y;i >= 0 && board[x][i] != 'B';i-- {
        if board[x][i] == 'p' {
            ans++
            break
        }
    }
    for i := x;i < len(board[0]) && board[x][i] != 'B';i++ {
        if board[x][i] == 'p' {
            ans++
            break
        }
    }
    return ans
}
```