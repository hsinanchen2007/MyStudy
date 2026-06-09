```
func maxAreaOfIsland(grid [][]int) int {
    if len(grid)<=0{
        return 0
    }
    h := len(grid)
    w := len(grid[0])
    var max int
    for i:=0;i<h;i++{
        for j:=0;j<w;j++{
            if grid[i][j]==1{ //如果等于1，计算出该点相邻的所有1
                temp := getAll(grid,i,j)
                if temp > max{
                    max = temp
                }
            }
        }
    }
    return max
}


func getAll(grid [][]int,x,y int)int{
    h := len(grid)
    w := len(grid[0])
    var res int
    if grid[x][y]==1{
        grid[x][y]=0 //该点置为0
        //  return 1+getAll(grid,x-1,y)+getAll(grid,x+1,y)+getAll(grid,x,y-1)+getAll(grid,x,y+1)
       if x-1>=0&&grid[x-1][y]==1{ //上节点为1
            res +=getAll(grid,x-1,y)
       }
        if x+1<h&&grid[x+1][y]==1{ //上节点为1
            res +=getAll(grid,x+1,y)
       }
       if y-1>=0&&grid[x][y-1]==1{ //上节点为1
            res +=getAll(grid,x,y-1)
       }
       if y+1<w&&grid[x][y+1]==1{ //上节点为1
            res +=getAll(grid,x,y+1)
       }
       return res+1
    }
    return res
}
```
