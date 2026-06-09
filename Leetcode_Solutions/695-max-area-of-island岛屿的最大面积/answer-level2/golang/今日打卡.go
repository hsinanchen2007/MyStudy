### 解题思路
抄的作业

### 代码

```golang
func maxAreaOfIsland(grid [][]int) (area int) {
    var traverse func(i, j int) int
    MaxI, MaxJ := len(grid), 0
    if MaxI > 0 {
        MaxJ = len(grid[0])
    }
    traverse = func(i, j int) (ae int) {
        if i < 0 || i > MaxI-1 {
            return
        }
        if j < 0 || j > MaxJ-1 {
            return
        }
        v := grid[i][j]
        grid[i][j] = -1
        if v != 1 {
            return
        }
        ae = v + traverse(i, j+1) + traverse(i+1, j) + traverse(i-1, j) + traverse(i, j-1)
        return
    }
    for i:=0; i<MaxI; i++ {
        for j:=0; j<MaxJ; j++ {
            if grid[i][j] != 1 {
                continue
            }
            tmp := traverse(i, j)
            if tmp > area {
                area = tmp
            }
        }
    }
    return
}

```