### 解题思路

### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
    if len(grid) == 0 {
		return 0
	}
    var n,m = len(grid),len(grid[0])
    var find [][]bool
    var local int
    var max = math.MinInt32
    // 初始化状态表
    for i:=0;i<n;i++{
        var list []bool
        for j:=0;j<m;j++{
            list = append(list,false)
        }
        find = append(find,list)
    }
    // 处理
    for i:=0;i<n;i++{
        for j:=0;j<m;j++{
            if find[i][j] == false && grid[i][j] == 1{
                local = DFS(grid,find,i,j,n,m)
                if local > max {
                    max = local
                }
            }
        }
    }
    if max == math.MinInt32{
        max = 0
    }
    return max
}

func DFS(grid [][]int,find [][]bool,x int,y int,n int,m int) int {
    if x >= n || x < 0 || y < 0|| y >=m {
        return 0
    }
    if find[x][y] == true || grid[x][y] == 0{
        return 0
    }else{
        find[x][y] = true
        return 1+ DFS(grid,find,x,y-1,n,m) + DFS(grid,find,x,y+1,n,m)  + DFS(grid,find,x-1,y,n,m) + DFS(grid,find,x+1,y,n,m)
    }
}

```