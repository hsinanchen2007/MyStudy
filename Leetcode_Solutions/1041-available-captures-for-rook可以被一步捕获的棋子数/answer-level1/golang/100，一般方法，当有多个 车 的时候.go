### 解题思路
此处撰写解题思路

### 代码

```golang
func numRookCaptures(board [][]byte) int {
	rSlice:=make([][]int,0)
    //当有多个 车的时候，遍历出所有的车
	for i:=0;i< len(board);i++{
		for j:=0;j< len(board[0]);j++{
			if board[i][j]=='R'{
				rSlice= append(rSlice,[]int{i,j} )
			}
		}
	}
	res:=0
    //对每一个车，都去看它前后左右四个方向的 有没有 'p'
	for i:=0;i< len(rSlice);i++{
		res+=helpNumRookCaptures(&board,rSlice[i])
	}
	return res
}

func helpNumRookCaptures(board *[][]byte,point []int) int{
	direction:=[][]int{{-1,0},{0,-1},{1,0},{0,1}}
	count:=0
	for i:=0;i<4;i++{
		for k:=1;point[0]+k*direction[i][0]>=0&&point[0]+k*direction[i][0]< len(*board)&&point[1]+k*direction[i][1]>=0&&point[1]+k*direction[i][1]<len((*board)[0]);k++{
			x:=point[0]+k*direction[i][0]
			y:=point[1]+k*direction[i][1]
			if (*board)[x][y]=='p'{
				count++
                //如果 路上遇到'p'就将它变为 'T'或者其他任何字符都行，并跳出
				(*board)[x][y]='T'
				break
                //路上遇到 友军直接跳出
			}else if (*board)[x][y]=='B'{
				break
			}
		}
	}
	return count
}
```