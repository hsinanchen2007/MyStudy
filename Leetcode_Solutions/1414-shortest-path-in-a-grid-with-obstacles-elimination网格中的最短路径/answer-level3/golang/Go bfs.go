贴份`GO`的代码


做法一样, $bfs$的 记录 $vis(i, j, k)$

```go
type node struct {
    x int
    y int
    k int
    step int
}

var vis [44][44][1644]bool

var fx = []int{0,0,1,-1}
var fy = []int{1,-1,0,0}

func Init(n, m int) {
    for i:=0;i<n;i++ {
        for j:=0;j<m;j++ {
            for k:=0;k<=n*m; k++ {
                vis[i][j][k] = false
            }
        }
    }
}

func shortestPath(grid [][]int, k int) int {
    n := len(grid)
    m := len(grid[0])
    
    Init(n, m)
    
    queue := list.New()
    queue.PushBack(node{0,0,0,0})
    
    for queue.Len() > 0 {
        qf := queue.Front()
        u := qf.Value.(node)
        fmt.Println(u.x, u.y, u.k, u.step)
        if u.x == n-1 && u.y == m-1{
            return u.step
        } 
        queue.Remove(qf)
        
        for i:=0; i<4; i++ {
            xx := u.x+fx[i]
            yy := u.y+fy[i]
            step := u.step + 1
            if xx<0 || xx>=n {
                continue
            }
            if yy<0 || yy>=m {
                continue
            }
            kk := u.k + grid[xx][yy]
            if vis[xx][yy][kk] == true || kk > k {
                continue
            }
            vis[xx][yy][kk] = true
            queue.PushBack(node{xx, yy, kk, step})
        }
    }
    
    return -1
}
```
