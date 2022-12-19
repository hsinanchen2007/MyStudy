

```
func orangesRotting(grid [][]int) int {
    // 广度优先遍历
    // 将所有为2的位置入队列，将能感染的位置继续放入队列，直到队列为空，记录所需时间
    // 记录为1的个数，感染一个减1，若最后还有为1的，返回-1
    iList := []int{0,0,-1,1}
    jList := []int{1,-1,0,0}
    queue := make([]int, 0, 100)
    hash := make(map[int]int, 0)
    oneNum := 0
    m := len(grid)
    n := len(grid[0])
    ret := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 2 {
                pos := i * n + j
                queue = append(queue, pos)
                hash[pos] = 0
            } else if grid[i][j] == 1 {
                oneNum++
            }
        }
    }
    for len(queue) > 0 {
        pos := queue[0]
        queue = queue[1:]
        i := pos / n
        j := pos % n
        for p := 0; p < 4; p++ {
            newI := i + iList[p]
            newJ := j + jList[p]
            if inRange(newI, newJ, m, n) && grid[newI][newJ] == 1 {
                grid[newI][newJ] = 2
                newPos := (newI) * n + newJ
                queue = append(queue, newPos)
                hash[newPos] = hash[pos] + 1
                ret = hash[newPos]
                oneNum--
            }
        }
    }
    if oneNum > 0 {
        return -1
    }
    return ret
}

func inRange(i, j, m, n int) bool {
    if i >= 0 && i < m && j >= 0 && j < n {
        return true
    }
    return false
}
```
