

![image.png](https://pic.leetcode-cn.com/a7516c647ee882fc060770a50ddb43fd23c9f2887344b24e524b5a5da9cdd3ac-file_1575687929407)


### 解题思路
一次 DFS 标记完第一个岛屿，碰到 0 （边界）即加入队列并返回（不需要再扩散）。
第二次 BFS 搜索到达第二个岛屿的最短路径，这里注意要将已访问过的位置标记避免重复访问。

### 代码

```golang
func shortestBridge(grid [][]int) int {
    size := len(grid)
    if size < 1 {
        return 0
    }

    queue := newQueue()

    loop:
    for i := range grid {
        for j := range grid[i] {
            if grid[i][j] == 1 {
                dfs(grid, i, j, queue)
                break loop
            }
        }
    }

    for {
        if len(*queue) < 1 {
            break
        }
        pos := queue.Dequeue()
        i, j, d := pos.i, pos.j, pos.depth

        if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[i]) || 
        (grid[i][j] != 1 && grid[i][j] != 0){
            continue
        }

        if grid[i][j] == 1 {
            return d - 1
        }
        // 标记访问
        grid[i][j] = -1
        
        queue.Enqueue(newPos(i+1, j, d+1))
        queue.Enqueue(newPos(i-1, j, d+1))
        queue.Enqueue(newPos(i, j+1, d+1))
        queue.Enqueue(newPos(i, j-1, d+1))
    }
    return -1
}

func dfs(grid [][]int, i, j int, q *queue) {
    if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[i]) {
        return
    }

    if grid[i][j] == 0 {
        // 到达边界，坐标入队并停止搜索
        q.Enqueue(newPos(i, j, 1))
    } else if grid[i][j] == 1 {
        grid[i][j] = 2

        dfs(grid, i+1, j, q)
        dfs(grid, i-1, j, q)
        dfs(grid, i, j+1, q)
        dfs(grid, i, j-1, q)
    }
}

func newPos(i, j, d int) *pos {
    return &pos{
        i: i,
        j: j,
        depth: d,
    }
}

type pos struct {
    i int
    j int
    depth int
}

func newQueue() *queue {
    q := make([]*pos, 0)
    return (*queue)(&q)
}

type queue []*pos

func (q *queue) Enqueue(p *pos) {
    *q = append(*q, p)
}

func (q *queue) Dequeue() *pos{
    if len(*q) > 0 {
        p := (*q)[0]
        *q = (*q)[1:]
        return p
    }
    return nil
}
```