### 解题思路
DFS

### 代码

```golang
func countNumber(n int) int{
	res:=0
	for n > 0{
		res += n%10
		n = n/10
	}
	return res
}

func movingDFS(m int,n int,k int,nowX int,nowY int,res *int,Flag [][]int){
	if countNumber(nowX)+countNumber(nowY) > k{
		return
	}
	if Flag[nowX][nowY] == 0{
		*res = *res+1
		Flag[nowX][nowY] = 1
	}
	if nowX < m-1 && Flag[nowX+1][nowY] == 0{
		movingDFS(m, n, k, nowX+1, nowY, res, Flag)
	}
	if nowY < n-1 && Flag[nowX][nowY+1] == 0{
		movingDFS(m, n, k, nowX, nowY+1, res, Flag)
	}
	if nowX > 0 && Flag[nowX-1][nowY] == 0{
		movingDFS(m, n, k, nowX-1, nowY, res, Flag)
	}
	if nowY > 0 && Flag[nowX][nowY-1] == 0{
		movingDFS(m, n, k, nowX, nowY-1, res, Flag)
	}
}

func movingCount(m int, n int, k int) int {
	res:=0
	Flag := make([][]int,0)
	for i:=0;i<m;i++{
		tmp := make([]int,n)
		Flag = append(Flag,tmp)
	}
	movingDFS(m,n,k,0,0,&res,Flag)
	return res
}
```