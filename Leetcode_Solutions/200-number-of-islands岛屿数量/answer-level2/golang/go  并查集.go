### 解题思路
并查集

### 代码

```golang
var temp []int

func find(x int) int {
	if temp[x]==x {
		return x
	}
	temp[x]=find(temp[x])
	return temp[x]


}
func numIslands(grid [][]byte) int {
	n:=len(grid)
	if len(grid)==0{
		return 0
	}
	m:=len(grid[0])
	temp=make([]int,m*n)
	for i:=0;i<n ;i++  {
		for j:=0;j<m ;j++  {
			temp[i*m+j]=i*m+j
		}

	}
	for i:=0;i<n ;i++  {
		for j:=0;j<m ;j++  {
			if grid[i][j]=='1'{
				if i>0 && grid[i-1][j]=='1'{
					a:=find(temp[(i-1)*m+j])
					b:=find(temp[(i)*m+j])
					temp[b]=a

				}
				if j>0 && grid[i][j-1]=='1'{
					a:=find(temp[i*m+j-1])
					b:=find(temp[(i)*m+j])
					temp[b]=a

				}
			}
		}

	}
	res:=0
	for i:=0;i<n ;i++  {
		for j:=0;j<m ;j++  {
			if grid[i][j]=='1' {
				a:=find(i*m+j)
				if a==i*m+j{
					res++
				}
			}

		}
		}
		return res

}
```