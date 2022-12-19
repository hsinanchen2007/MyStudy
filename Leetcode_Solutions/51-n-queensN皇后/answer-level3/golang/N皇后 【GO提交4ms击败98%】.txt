## 结果

![image.png](https://pic.leetcode-cn.com/451fd96c017f10655e34e722d255714d4e2c2787ebafaef0b0f1a4927df03f89-image.png)

## 思路

用回溯法，首先算法的每一步都在棋盘上新的一行放置一个皇后（因为不可能出现一行两个皇后）。
- 放置皇后时，需要考虑放置皇后的所在列没有皇后，以及皇后所在位置的四个斜对角方向没有皇后
- 实现很直观，代码如下


## Code

```
func solveNQueens(n int) (result [][]string) {
    board := makeBoard(n)
    place(n, 0, board, &result)
    return
}

func place(n, row int, board [][]byte, result *[][]string) {
    if row == n {
        cp := make([]string, n)
        for i := range board {
            cp[i] = string(board[i])
        }
        *result = append(*result, cp)
        return
    }
    for i := range board[row] {
        // 垂直是否有
        for j:=0;j<n;j++ {
            if board[j][i] != '.' {
                goto next
            }
        }
        // 斜对角 row， i
        for a,b := row-1,i-1; a>=0 && b >= 0; {
            if board[a][b] != '.' {
                goto next
            }
            a--
            b--
        }
        for a,b := row-1,i+1; a>=0 && b < n; {
            if board[a][b] != '.' {
                goto next
            }
            a--
            b++
        }
        for a,b := row+1,i-1; a < n && b >= 0; {
            if board[a][b] != '.' {
                goto next
            }
            a++
            b--
        }
        for a,b := row+1,i+1; a < n && b < n; {
            if board[a][b] != '.' {
                goto next
            }
            a++
            b++
        }
        // 放置-》下一步
        board[row][i] = 'Q'
        place(n, row+1, board, result)
        board[row][i] = '.'
    next:
        continue
    }
}


func makeBoard(n int) [][]byte {
    result := make([][]byte, n)
    for i := range result {
        s := make([]byte, n)
        for i :=0;i<n;i++ {
            s[i] = '.'
        }
        result[i] = s
    }
    return result
}
```

