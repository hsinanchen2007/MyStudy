### 题中没有说只能吃一次卒，这个坑了
```
func numRookCaptures(board [][]byte) int {
    var Ri, Rj int
    for i1, j1 := range board{
        for i2, j2 := range j1{
            if j2 == 'R'{   //遇到车，记住坐标
            Ri = i1
            Rj = i2
            }
        }
    }

    //使用count统计可以吃的卒
    var count int
    //先遍历车在的行是否有可以吃的卒子
    for i := Rj; i < 8; i++{
        if board[Ri][i] == 'p'{
            count++
            break
        }
        if board[Ri][i] == 'B'{
            break
        }
    }

    for i := Rj; i > 0; i--{
        if board[Ri][i] == 'p'{
            count++
            break
        }
        if board[Ri][i] == 'B'{
            break
        }
    }

    //遍历车在的列是否有可以吃的卒子
    for i := Ri; i < 8; i++{
        if board[i][Rj] == 'p'{
            count++
            break
        }
        if board[i][Rj] == 'B'{
            break
        }
    }

    for i := Ri; i > 0; i--{
        if board[i][Rj] == 'p'{
            count++
            break
        }
        if board[i][Rj] == 'B'{
            break
        }
    }

    return count
}
```
