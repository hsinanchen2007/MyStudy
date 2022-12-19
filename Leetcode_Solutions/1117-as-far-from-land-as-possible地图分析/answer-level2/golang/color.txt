### 解题思路
此处撰写解题思路

### 代码

```golang
func maxDistance(grid [][]int) int {
    time := 0
    x := 0
    color := 1
    for x == 0{
    for i := range grid{
        for j := range grid[i]{
            if grid[i][j] == color{
                if i > 0 && grid[i-1][j] == 0{
                    x = 1
                    grid[i-1][j] = color + 1
                }
                if j > 0 && grid[i][j-1] == 0{
                    x = 1
                    grid[i][j-1] = color + 1
                } 
                if j < len(grid[i])-1 && grid[i][j+1] == 0{
                    x = 1
                    grid[i][j+1] = color + 1
                } 
                if i < len(grid[i])-1 && grid[i+1][j] == 0{
                    x = 1
                    grid[i+1][j] = color + 1
                }  
            }
        }
    }
    if x == 1{
        color += 1
        time += 1
    }
    if x == 0 && time == 0{
        return -1
    }
    
    if x == 0 {
        break
    }
    x = 0
}
return time
}

```