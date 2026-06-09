### 解题思路
就是很简单的先找到所有的陆地，然后通过BFS的方法（每次将陆地旁的所有海洋转换为陆地，并count++），直到没有陆地为止

### 代码

```golang
type point struct {
    x int
    y int
}

func maxDistance(grid [][]int) int {
    var (
        count int
        stack []*point
    )
    for i := 0; i < len(grid); i ++ {
        for j := 0; j < len(grid[0]); j ++ {
            if grid[i][j] == 1 {
                stack = append(stack,&point{x:i,y:j})
            }
        }
    }
    for len(stack) != 0 {
        temp := stack
        stack = []*point{}
        for _,val := range temp {
            i := val.x
            j := val.y
            if i + 1 < len(grid) && grid[i+1][j] == 0 {
                grid[i+1][j] = 1
                stack = append(stack,&point{x:i+1,y:j})
            }
            if j + 1 < len(grid[0]) && grid[i][j+1] == 0 {
                grid[i][j+1] = 1
                stack = append(stack,&point{x:i,y:j+1})
            }
            if i - 1 >= 0 && grid[i-1][j] == 0 {
                grid[i-1][j] = 1
                stack = append(stack,&point{x:i-1,y:j})
            }
            if j -1 >= 0 && grid[i][j-1] == 0 {
                grid[i][j-1] = 1
                stack = append(stack,&point{x:i,y:j-1})
            }
        }
        if len(stack) != 0 {
            count ++
        }
    }
    if count == 0 {
        return -1
    }
    return count
}
```