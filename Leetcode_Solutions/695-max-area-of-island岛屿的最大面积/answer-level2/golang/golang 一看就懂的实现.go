```
func maxAreaOfIsland(grid [][]int) int {
    if grid == nil || len(grid) == 0{
        return 0
    }
    N := len(grid)
    M := len(grid[0])
    res := 0
    for i := 0;i<N;i++{
        for j := 0;j<M;j++{
            if grid[i][j] == 1{
                res = max(res,mark(grid,i,j,N,M)) 
            }
        }
    }
    return res
}

func mark(grid [][]int,i,j,N,M int) int {
    if i<0 || i>=N ||j<0 ||j>=M||grid[i][j] != 1{
        return 0
    }
    var res = 1
    grid[i][j] =2
    res +=mark(grid,i+1,j,N,M)
    res +=mark(grid,i-1,j,N,M)
    res +=mark(grid,i,j+1,N,M)
    res +=mark(grid,i,j-1,N,M)
    return res
}

func max(a,b int)int{
    if a<b{
        return b 
    }  
    return a
}
```
