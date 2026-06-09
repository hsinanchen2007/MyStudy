```
type point struct {
	x int
	y int
}

//DFS
func movingCount(m int, n int, k int) int {

	res := 0
	temp := [][]int{}
	for i := 0 ; i < m ; i ++{
		t := make([]int,n)
		temp = append(temp, t)
	}
	if 0<= k {
		res++
		temp[0][0] = 1
	}
	DFSSS(m,n,0, 0,temp,&res,k)
	return res
}

unc DFSSS(m,n int,x int,y int,temp [][]int,res *int,k int){
	dx := []int{-1,0,1,0}
	dy := []int{0,1,0,-1}
	for i := 0 ; i < 4; i ++{
		newx := x + dx[i]
		newy := y + dy[i]
		if newx >= 0 && newx < m && newy >= 0 && newy < n && temp[newx][newy] == 0{
			if sum(newx) + sum(newy) <= k{
				*res ++
				temp[newx][newy] = 1
				DFSSS(m,n,newx,newy,temp,res,k)
			}
		}
	}
}


//BFS
func movingCount(m int, n int, k int) int {

	res := 0
	dx := []int{1,0,-1,0}
	dy := []int{0,1,0,-1}
	queue := []*point{}
	temp := [][]int{}
	for i := 0 ; i < m ; i ++{
		t := make([]int,n)
		temp = append(temp, t)
	}
	if 0 <= k {
		res ++
		temp[0][0] = 1
	}
	start := &point{
		x: 0,
		y: 0,
	}
	queue = append(queue, start)
	
	for len(queue)!= 0{
		q := queue
		queue = []*point{}
		for _,val := range q{
			x := val.x
			y := val.y
			for i := 0 ; i < 4 ; i ++{
				newx := x + dx[i]
				newy := y + dy[i]
				if newx >=0 && newx < m && newy >= 0 && newy < n && temp[newx][newy] ==0{
					if sum(newx) + sum(newy) <= k{
						res ++
						temp[newx][newy] = 1
						queue = append(queue, &point{
							x: newx,
							y: newy,
						})
					}
				}
			}
		}
	}

	return res

}
func sum(x int)int{
	res := 0
	for x != 0{
		res += x % 10
		x = x/10
	}
	return res
}
```
