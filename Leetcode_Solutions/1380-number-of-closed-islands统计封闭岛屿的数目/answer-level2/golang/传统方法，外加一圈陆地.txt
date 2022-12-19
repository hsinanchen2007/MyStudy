### 解题思路
此处撰写解题思路

### 代码

```golang
func closedIsland(grid [][]int) int {

	n:=len(grid)+2
	m:=len(grid[0])+2
	visit := make([][]int,n)
    old := make([][]int,n)
	for i:=0;i<n;i++{
		visit[i]=make([]int,m)
        old[i]=make([]int,m)
	}

    for i:=1;i<n-1;i++{
        for j:=1;j<m-1;j++{
            old[i][j]=grid[i-1][j-1]
        }
    }
    // fmt.Printf("%v\n",old)

	var count int
	for i:=0;i<n;i++{
		for j:=0;j<m;j++{
			if old[i][j] == 0 && visit[i][j]==0 {
               // fmt.Printf("i:%v,j:%v\n",i,j)
				isIsland(old,visit,i,j)  
                if i == 0|| i==n-1 || j==0 || j==m-1{
                    continue
                }            
				count++
			}
		}
	}
   // fmt.Printf("%v\n",visit)
    return count 
}

func isIsland(old [][]int, visit [][]int, x int, y int){
	if x<0 || x>=len(old) {
		return
	}
	if y<0 || y>=len(old[0]) {
		return
	}
    if old[x][y] == 1  {
        return 
    }
    if visit[x][y] == 1{
        return 
    }

	visit[x][y]=1
	isIsland(old,visit,x-1,y)
	isIsland(old,visit,x+1,y)
	isIsland(old,visit,x,y-1)
	isIsland(old,visit,x,y+1)

}
```