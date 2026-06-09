# 1. BFS
- 使用额外切片使用广度优先染色
```
var dx = [4]int{-1, 1, 0, 0}
var dy = [4]int{0, 0, 1, -1}
var row, col int
func numIslands(grid [][]byte) int {
    row = len(grid)
    if row == 0{
        return 0
    }
    
    col = len(grid[0])
    count := 0
    for i:=0; i<row; i++{
        for j:=0; j<col; j++{
            if grid[i][j] == '1'{
                BFS(grid, i, j)
                count++
            }
        }
    }
    return count
}

func BFS(grid [][]byte, i, j int){
    queue := make([]int, 0)
    queue = append(queue, i, j)
    grid[i][j] = '0'
    for len(queue) != 0{
        i, j := queue[0], queue[1]
        queue = queue[2:]
        for m:=0; m<4; m++{
            tmp_i := i + dx[m]
            tmp_j := j + dy[m]
            
            if 0<=tmp_i && tmp_i<row && 0<=tmp_j && tmp_j<col && grid[tmp_i][tmp_j] == '1'{
                grid[tmp_i][tmp_j] = '0'
                queue = append(queue, tmp_i, tmp_j)
            }
        }
    }
}
```
# 2. DFS
- 递归染色左右上下位置
```
var dx = [4]int{-1, 1, 0, 0}
var dy = [4]int{0, 0, 1, -1}
func numIslands(grid [][]byte) int {
    m := len(grid)
    if m == 0{
        return 0
    }
    
    n := len(grid[0])
    count := 0
    for i:=0; i<m; i++{
        for j:=0; j<n; j++{
            if grid[i][j] == '1'{
                DFS(grid, i, j)
                count++
            }
        }
    }
    return count
}

func DFS(grid [][]byte, i, j int){
    if i<0 || j<0 || i >= len(grid) || j >=len(grid[0]) || grid[i][j] != '1'{
        return
    }
    
    grid[i][j] = '0'
    for k:=0; k < 4; k++{
        DFS(grid, i+dx[k], j+dy[k])
    }
}
```
3. 并查集
- 使用路径压缩和rank排名
```
var dx = [4]int{-1, 1, 0, 0}
var dy = [4]int{0, 0, 1, -1}
var row, col int
var parent []int
var count int
var rank []int
func numIslands(grid [][]byte) int {
    row = len(grid)
    if row == 0{
        return 0
    }
    
    col = len(grid[0])
    //path compress
    count = 0
    parent = make([]int, row*col) 
    rank = make([]int, row*col)
    for i:=0; i<row; i++{
        for j:=0; j<col; j++{
            if grid[i][j] == '1'{
                parent[i*col+j] = i*col + j
                count++
            }
        }
    }
    
    for i:=0; i<row; i++{
        for j:=0; j<col; j++{
            if grid[i][j] == '1'{
                for k:=0; k<4; k++{
                    nr, nc := i+dx[k], j+dy[k]
                    if isValid(grid, nr, nc) && grid[nr][nc] == '1'{
                        union(i*col + j, nr*col + nc)
                    }
                }
            }
        }
    }
    return count
}
func isValid(grid [][]byte, i, j int)bool{
    return !(i < 0 || i >= row || j <0 || j>=col)
}

func find(i int)int{
    if parent[i] != i{
        parent[i] = find(parent[i])
    }
    return parent[i]
}

func union(x, y int){
    rootx := find(x)
    rooty := find(y)
    
    //rank 
    if rootx != rooty{
        if rank[rootx] > rank[rooty]{
            parent[rooty] = rootx
        }else if rank[rootx] < rank[rooty]{
            parent[rootx] = rooty
        }else{
            parent[rooty] = rootx
            rank[rootx] += 1
        }  
        count -= 1
    }
    
} 

```
