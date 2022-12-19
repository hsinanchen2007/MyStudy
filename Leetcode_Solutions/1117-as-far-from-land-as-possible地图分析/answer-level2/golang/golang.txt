### 解题思路
...

### 代码

```golang
func maxDistance(grid [][]int) int {
    var rQueue []int
    var lQueue []int
    for i:= 0;i < len(grid);i++ {
        for j:=0;j < len(grid[i]);j++ {
            if grid[i][j] == 1 {
                rQueue = append(rQueue, i)
                lQueue = append(lQueue, j)
            }
        }
    }
    if len(rQueue) == 0 || len(rQueue) == len(grid)*len(grid){
        return -1
    }

    depth := -1
    for len(rQueue) > 0 {
        depth++
        N := len(rQueue)
        for i:=0;i<N;i++{
            r := rQueue[0]
            l := lQueue[0]
            rQueue = rQueue[1:]
            lQueue = lQueue[1:]
            if r-1 >= 0 && grid[r-1][l] == 0 {                
                grid[r-1][l] = 2
                rQueue = append(rQueue, r-1)
                lQueue = append(lQueue, l)
            }
            if r+1 < len(grid) && grid[r+1][l] == 0 {
                grid[r+1][l] = 2
                rQueue = append(rQueue, r+1)
                lQueue = append(lQueue, l)
            }
            if l - 1 >= 0 && grid[r][l-1] == 0 {
                grid[r][l-1] = 2
                rQueue = append(rQueue, r)
                lQueue = append(lQueue, l-1)
            }
            if l + 1 < len(grid) && grid[r][l+1] == 0 {
                grid[r][l+1] = 2
                rQueue = append(rQueue, r)
                lQueue = append(lQueue, l+1)
            }
        }
    }
    return depth
}

```