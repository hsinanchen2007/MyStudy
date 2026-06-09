### 代码

```golang
func gameOfLife(board [][]int)  {
    x:=len(board)
    y:=len(board[0])
    if x==0||y==0{
        return 
    }
    
    res:=make([][]int,x)
    for i:=0;i<x;i++{
        res[i]=make([]int,y)
    } 

    for i:=0;i<x;i++{
        for j:=0;j<y;j++{
            sum:=0
            if i!=0{
                if j!=0{
                    sum+=board[i-1][j-1]
                }
                if j!=y-1 {
                    sum+=board[i-1][j+1]
                }
                sum+=board[i-1][j]
            }
            if i+1!=x{
                if j!=0{
                    sum+=board[i+1][j-1]
                }
                if j!=y-1 {
                    sum+=board[i+1][j+1]
                }
                sum+=board[i+1][j]
            }
            if j!=0{
                sum+=board[i][j-1]
            }
            if j+1!=y{
                sum+=board[i][j+1]
            }
            if board[i][j]==1{
                if sum==2||sum==3{
                    res[i][j]=1
                }
            }else{
                if sum==3{
                    res[i][j]=1
                }
            }
            
        }
        
        
    }

    for i:=0;i<x;i++{
        for j:=0;j<y;j++{
            board[i][j]=res[i][j]
        }
    }




}
```