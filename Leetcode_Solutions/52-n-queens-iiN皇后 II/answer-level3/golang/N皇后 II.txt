## 结果

![image.png](https://pic.leetcode-cn.com/5c118727c2adb7559b00aa8fc3f0e65e525782ae96556d11e51558bf20446b58-image.png)

## 思路

回溯法，与[N皇后](https://leetcode-cn.com/problems/n-queens/)类似
- 每一步在棋盘新的一行中不同位置放置一个皇后，然后执行下一步
- 每一步的放置需要考虑是否引起冲突【皇后所在列没有皇后，四个对角方向没有皇后】

## Code

```
func totalNQueens(n int) (result int) {
    board := makeBoard(n)
    place(n, 0, board, &result)
    return
}

func place(n, row int, board [][]byte, result *int) {
    if row == n {
        *result++
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


