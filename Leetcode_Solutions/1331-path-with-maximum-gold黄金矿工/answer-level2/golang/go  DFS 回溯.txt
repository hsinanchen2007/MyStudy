### 解题思路
DFS 回溯

### 代码

```golang
var dx [4]int=[4]int{1,-1,0,0}
var dy  [4]int=[4]int{0,0,-1,1}
//var  max  int
func getMaximumGold(grid [][]int) int {
    if len(grid)==0 || len(grid[0])==0{
        return 0
    }
 max:=0
    for i:=0;i<len(grid);i++{
        for j:=0;j<len(grid[0]);j++{
            if grid[i][j]!=0{
               
               dfs(grid,i,j,0,&max)
               
               
            }
        }
    }
    return max
}
func dfs(grid [][]int, x int, y int,res int, max *int){
   
    temp:=grid[x][y]
    res+=grid[x][y]
    if res>*max{
        *max=res
    }
     grid[x][y]=0
    for i:=0;i<4;i++{
        sx:=x+dx[i]
        sy:=y+dy[i]
        if sx>=0 && sy>=0 && sx<len(grid) && sy<len(grid[0]) &&grid[sx][sy]!=0{
            dfs(grid,sx,sy,res,max)  
          
        }
    }
    grid[x][y]=temp
    
    
    
}
```