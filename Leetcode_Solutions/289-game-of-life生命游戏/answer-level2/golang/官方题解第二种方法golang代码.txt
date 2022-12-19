```
func gameOfLife(board [][]int)  {
    // -1,live -> dead
    // 2,dead -> live
    for i,row := range board{
        for j,_ := range row{
            life(i,j,board)
        }
    }
    for i := 0;i < len(board);i++{
        for j:= 0;j < len(board[0]);j++{
            if board[i][j] == -1{
                board[i][j] = 0
            }else if board[i][j] == 2{
                board[i][j] = 1
            }
        }
    }
}
func life(x,y int,board [][]int){
    var award = [8][2]int{{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}}
    liveNum := 0
    for _,val := range award{
        newX := x + val[0]
        newY := y + val[1]
        if newX >= 0 && newX < len(board) && newY >= 0 && newY < len(board[0]){
            if board[newX][newY] == 1 || board[newX][newY] == -1{
                liveNum++
            }
        } 
    }
    if board[x][y] == 0{
        if liveNum == 3{
            board[x][y] = 2
        }
    }else{
        if liveNum < 2 || liveNum > 3{
            board[x][y] = -1
        }
    }
}
```
