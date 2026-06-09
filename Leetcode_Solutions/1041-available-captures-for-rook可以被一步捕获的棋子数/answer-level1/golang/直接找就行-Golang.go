### 解题思路
//按照题意，找到车坐标，开始往四个方向移动
//要注意的是一个方向上只能吃一个卒
//时间复杂度O(N^2)

### 代码
```golang

func numRookCaptures(board [][]byte) int {
    res := 0
    for i:=0;i<8;i++ {
        for j:=0;j<8;j++ {
            if board[i][j] == 'R' {
                //向右走
                for x:=j+1;x<8;x++ {
                    if board[i][x] == 'B' {
                        break
                    }
                    if board[i][x] == 'p' {
                        res++
                        break
                    }
                }
                //向左走
                for x:=j-1;x>=0;x-- {
                    if board[i][x] == 'B' {
                        break
                    }
                    if board[i][x] == 'p' {
                        res++
                        break

                    }
                }
                //向下走
                for x:=i+1;x<8;x++ {
                    if board[x][j] == 'B' {
                        break
                    }
                    if board[x][j] == 'p' {
                        res++
                        break
                    }
                }
                //向上走
                for x:=i-1;x>=0;x-- {
                    if board[x][j] == 'B' {
                        break
                    }
                    if board[x][j] == 'p' {
                        res++
                        break
                    }
                }
            }
        }
    }
    return res
}
```