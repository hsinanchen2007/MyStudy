### 解题思路
这题好难，用最简单的暴力破解 DFS+回溯 待优化
go这么直接的解法少，抛砖引玉一下
### 代码

```golang
func solveSudoku(board [][]byte)  {
    if board == nil || len(board) == 0{
        return 
    }
    _DFS(board)
}

func _DFS(board [][]byte) bool{
    for i:=0;i<9;i++{
        for j:=0;j<9;j++{
            if(board[i][j] == '.'){
                for v:=0;v<9;v++{
                    if(isValid(board,i,j,byte('1' + v))){
                        fmt.Println(byte('1' + v))
                        fmt.Println(v)

                        board[i][j] = byte('1' + v)
                        if(_DFS(board)){
                            return true
                        }else{
                            board[i][j] = '.'
                        }
                    }       
                }
                return false
            }
            
        }
    }
    return true
}

func isValid(board [][]byte ,row int,col int,v byte) bool{
    for r:= 0;r<9;r++{
        if(board[r][col] == v){
            return false
        }
        if(board[row][r] == v){
            return false
        }
        if(board[row/3*3 + r/3][3*(col/3) + r%3] == v){
            return false
        }
    }
    return true
}
```