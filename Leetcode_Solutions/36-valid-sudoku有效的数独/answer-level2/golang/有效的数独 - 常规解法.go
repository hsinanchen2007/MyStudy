
![image.png](https://pic.leetcode-cn.com/9b92d2eea2874d14f23803ba54e7186f7358d117c4fe2bd401f41b1aa5f26b8a-image.png)


## 思路

比较中规中矩，按题目要求先遍历行，再遍历列，最后遍历9个3x3分块，使用字典来确认数字是否重复
改进：`3类情况的判别都可以在一次遍历后完成，难点在于分块判别时如何将i，j映射到棋盘对应位置上`


```
func isValidSudoku(board [][]byte) bool {
    // 行列检测
    for i:=0;i<9;i++ {
        mp1 := map[byte]bool{}
        mp2 := map[byte]bool{}
        mp3 := map[byte]bool{}
        for j:=0;j<9;j++ {
            // row
            if board[i][j] != '.' {
                if mp1[board[i][j]] {
                    return false
                }
                mp1[board[i][j]] = true
            }
            // column
            if board[j][i] != '.' {
                if mp2[board[j][i]] {
                    return false
                }
                mp2[board[j][i]] = true
            }
            // part
            row := (i%3)*3 + j%3
            col := (i/3)*3 + j/3
            if board[row][col] != '.' {
                if mp3[board[row][col]] {
                    return false
                }
                mp3[board[row][col]] = true
            }
            
        }
    }
    return true
}
```
