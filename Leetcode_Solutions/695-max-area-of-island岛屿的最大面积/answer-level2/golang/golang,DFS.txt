### 解题思路
深度优先搜索

### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
    m := len(grid)
    if m==0 {
        return 0
    }

    n := len(grid[0])
    if n==0 {
        return 0
    }

    maxArea := 0
    for i:=0;i<m;i++ {
        for j:=0;j<n;j++ {
            if grid[i][j]==1 {
                tempArea := 0
                dfs(grid,i,j,&tempArea)
                maxArea=max(maxArea,tempArea)
            }
        }
    }

    return maxArea
}

func max(a,b int) int {
    if a>b {
        return a
    }
    return b
}

func dfs(grid [][]int,x int,y int,area *int) {
    if x<0 || x>=len(grid) || y<0 || y>=len(grid[0]) || grid[x][y]!=1 {
        return
    }

    *area += 1
    grid[x][y]=0

    dfs(grid,x+1,y,area)
    dfs(grid,x-1,y,area)
    dfs(grid,x,y-1,area)
    dfs(grid,x,y+1,area)
}
```