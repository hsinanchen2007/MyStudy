```
type Position struct {
    X int
    Y int
}

func orangesRotting(grid [][]int) int {
    if len(grid)==0{
        return 0
    }
    queue := []Position{}
    for i, v := range grid {
        for j, v1 := range v {
            if v1 == 2 {
                queue = append(queue, Position{X:i, Y:j})
            }
        }
    }

    row := len(grid)
    column := len(grid[0])
    count := 0
    for len(queue) > 0 {
        temp := []Position{}
        count++
        for _, v := range queue {
            if v.X - 1 >= 0 {
                if grid[v.X - 1][v.Y] == 1 {
                    temp = append(temp, Position{X: v.X-1,Y:v.Y})
                    grid[v.X - 1][v.Y] = 2
                }
            }
            if v.Y - 1 >= 0 {
                if grid[v.X][v.Y - 1] == 1 {
                    temp = append(temp, Position{X: v.X,Y:v.Y-1})
                    grid[v.X][v.Y - 1] = 2
                }
            }

            if v.X + 1 < row {
                if grid[v.X+1][v.Y] == 1 {
                    temp = append(temp, Position{X: v.X+1,Y:v.Y})
                    grid[v.X+1][v.Y] = 2
                }
            }
            if v.Y + 1 < column {
                if grid[v.X][v.Y+1] == 1 {
                    temp = append(temp, Position{X: v.X,Y:v.Y+1})
                    grid[v.X][v.Y+1] = 2
                }
            }
        }
        queue = temp
    }
    for _, v := range grid {
        for _, v1 := range v {
            if v1 == 1 {
                return -1
            }
        }
    }
    if count == 0 {
        return 0
    }
    return count-1
}
```
