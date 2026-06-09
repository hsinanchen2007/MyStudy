### 解题思路
原地方法的关键在于标记的选择。
对于状态的更新:
2 死亡
1 仍然存活，不改变
-2 复活

这样设定不会影响后面的结果

### 代码

```golang
func gameOfLife(board [][]int)  {
    //2 死亡
    //1 仍然存活，不改变
    //-2 复活
    
    for i:=0;i<len(board);i++ {
        for j:=0;j<len(board[0]);j++ {
            //上边
            l1 := i-1
            //左边
            l2 := j-1
            //右边
            l3 := i+1
            //下边
            l4 := j+1
            count := 0
            //对每个board[i][j]进行判断
            if l1 >= 0 {
                if board[l1][j] >= 1 {
                    count++
                }
                if l2 >= 0 && board[l1][l2] >= 1 {
                    count++
                }
                if l4 < len(board[0]) && board[l1][l4] >= 1 {
                    count++
                }
                // fmt.Println("上",i,j,count)
            }
            if l2 >= 0 && board[i][l2] >= 1 {
                count++
                // fmt.Println("左",i,j,count)
            }
            if l4 < len(board[0]) && board[i][l4] >= 1 {
                // fmt.Println("右",i,j,count)
                count++
            }
            if l3 < len(board) {
                if l4 < len(board[0]) && board[l3][l4] >= 1 {
                    count++
                } 
                if board[l3][j] >= 1 {
                    count++
                }
                if l2 >= 0 && board[l3][l2] >= 1 {
                    count++
                }
                // fmt.Println("下",i,j,count)
            }
            if (count < 2 || count >3) && board[i][j] == 1{ //dead
                board[i][j] = 2
            } else if (count == 2 || count == 3)  && board[i][j] == 1  { //alive
                board[i][j] = 1
            } else if count == 3 && board[i][j] == 0 { //reback
                board[i][j] = -2
            }
            // fmt.Println(i,j,board,count)
        }
    }

    for i:=0;i<len(board);i++ {
        for j:=0;j<len(board[0]);j++ {
            if board[i][j] == 2 {
                board[i][j] = 0
            } else if board[i][j] == -2 {
                board[i][j] = 1
            }
        }
    }

}
```