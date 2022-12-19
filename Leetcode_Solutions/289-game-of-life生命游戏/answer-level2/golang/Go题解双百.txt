其实就是先统计细胞的状态，然后再统一更新
譬如：
当细胞存活时，使细胞死亡的点在于：
如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
当我们检测到这类细胞时，将这类细胞的状态更新为2
当细胞死亡时，使细胞复活的点在于：
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
当我们监测到这类细胞时，将这类细胞的状态更新为1

那么相应的，监测细胞周围活细胞的条件为，当身边活细胞状态为>0时，可知它是活细胞

这样确认完所有状态后，下一次一次性更新所有状态即可

```golang
func gameOfLife(board [][]int)  {
	for i:=0;i<len(board);i++{
		for j:=0;j<len(board[0]);j++{
			temp:=countCellsAlive(board,i,j)
            if i==0&&j==1{
				fmt.Println(temp)
			}
			if board[i][j]==0{
				if temp==3{
					board[i][j]=-1
				}
			}else{
				if temp<2||temp>3{
					board[i][j]=2
				}
			}
		}
	}
	for i:=0;i<len(board);i++{
		for j:=0;j<len(board[0]);j++{
			if board[i][j]==2{
				board[i][j]=0
			}
			if board[i][j]==-1{
				board[i][j]=1
			}
		}
	}
}
func countCellsAlive(board [][]int,i,j int) int{
	res:=0
	for m:=-1; m<=1; m++ {
		for n:=-1;n<=1;n++{
			if 0<=(i+m)&&(i+m)<len(board)&&(j+n)>=0&&(j+n)<len(board[0])&&board[i+m][j+n]>0{
				res++
			}
		}
	}
	if board[i][j]==1{
		res--
	}
	return res
}
```