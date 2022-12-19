### 解题思路
此处撰写解题思路

### 代码

```golang
func movingCount(m int, n int, k int) int {
	if m <= 0 {
		return 0
	}

	square := make([][]int,m)
	// 组装地图
	for i:=0;i<m;i++ {
		for j:=0;j<n;j++ {
			square[i] = append(square[i],1)
		}
	}

	x := 0
	searchSquare(square,0,0,k,&x)

	return x
}

func searchSquare(square [][]int,x,y,k int,n *int) {
	if square[x][y] == 0 {
		return
	}

	if snum(x) + snum(y) > k {
		return
	}

	square[x][y] = 0
	*n ++

	if x-1 >= 0 {
		searchSquare(square,x-1,y,k,n)
	}

	if x+1 <= len(square)-1 {
		searchSquare(square,x+1,y,k,n)
	}

	if y-1 >= 0  {
		searchSquare(square,x,y-1,k,n)
	}

	if y+1 <= len(square[0])-1 {
		searchSquare(square,x,y+1,k,n)
	}
}

func snum(x int) int {
	if x == 100 {
		return 1
	}else if x >= 10 && x <= 99 {
		return x/10 + x%10
	}else {
		return x
	}
}
```