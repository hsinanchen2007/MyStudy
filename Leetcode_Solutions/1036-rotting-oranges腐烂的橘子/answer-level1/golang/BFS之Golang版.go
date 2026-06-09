```
func orangesRotting(grid [][]int) int {
    var stack []int
    var ans, freshCnt int

    rows, cols := len(grid), len(grid[0])
    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if grid[i][j] == 2 {
                stack = append(stack, i, j)
            } else if grid[i][j] == 1 {
                freshCnt++
            }
        }
    }

    for {
        size, cnt := len(stack), 0
        if size == 0 {
            break
        }

        for i := 0; i < size; i += 2 {
            x, y := stack[i], stack[i+1]
            if x > 0 && grid[x-1][y] == 1 { //up
                grid[x-1][y] = 2
                stack = append(stack, x-1, y)
                cnt++
                freshCnt--
            }
            if y > 0 && grid[x][y-1] == 1 { //left
                grid[x][y-1] = 2
                stack = append(stack, x, y-1)
                cnt++
                freshCnt--
            }
            if y < cols-1 && grid[x][y+1] == 1 { //right
                grid[x][y+1] = 2
                stack = append(stack, x, y+1)
                cnt++
                freshCnt--
            }
            if x < rows-1 && grid[x+1][y] == 1 { //down
                grid[x+1][y] = 2
                stack = append(stack, x+1, y)
                cnt++
                freshCnt--
            }
        }

        if cnt > 0 {
            ans++
        }
        stack = stack[size:]
    }

    if freshCnt > 0 {
        return -1
    }
    return ans
}
```
