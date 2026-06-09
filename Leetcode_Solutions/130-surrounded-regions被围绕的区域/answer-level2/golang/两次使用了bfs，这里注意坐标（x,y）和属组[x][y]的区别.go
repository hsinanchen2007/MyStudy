### 解题思路
此处撰写解题思路

### 代码

```golang
type postion struct{
	x int
	y int
}

var isInValid bool

func solve(board [][]byte) {

	m:=len(board)
    if m == 0{
        return
    }
	n:=len(board[0])
    isInValid = false
	p:=make(map[postion]bool) //记录位置

	visit :=make([][]int,m)
	for i:=0;i<m;i++{
		visit[i] = make([]int,n)
	}

	for i:=0;i<m;i++{
		for j:=0;j<n;j++{
			if board[i][j] == 'O' && visit[i][j] != 1 {
				findArea(i,j,board, visit)
				if isInValid == true{
					isInValid = false
					continue
				}
				pTmp:=postion{
					i,
					j,
				}
				p[pTmp] = true
			}
		}
	}

	for k,v :=range p{
		if v==true{
			setValue(k.x,k.y,board)
           // fmt.Printf("x:%v,y:%v\n",k.x,k.y)
		}
	}

}

func findArea(i int, j int, board [][]byte, visit [][]int){
	m:=len(board)
	n:=len(board[0])
	if i<0|| i>=m{
		return
	}
	if j<0|| j>=n{
		return
	}
	if board[i][j] =='X' || visit[i][j]==1{
		return
	}
	if isEdge(i,j,m,n){
		isInValid = true
	}
	visit[i][j]=1

	findArea(i,j+1,board, visit)
	findArea(i,j-1,board, visit)
	findArea(i-1,j,board, visit)
	findArea(i+1,j,board, visit)
}

func isEdge(i int, j int, m int ,n int )bool{
	if i == 0 || i == m-1 || j == 0 || j == n-1{
		return true
	}
	return false

}

func setValue(i int,j int, board [][]byte){
	m:=len(board)
	n:=len(board[0])
	if j<0|| j>=n{
		return
	}
	if i<0|| i>=m{
		return
	}
	if board[i][j] =='O' {
		board[i][j] = 'X'
	}else{
        return 
    }

	setValue(i-1,j,board)
	setValue(i+1,j,board)
	setValue(i,j-1,board)
	setValue(i,j+1,board)
}
```