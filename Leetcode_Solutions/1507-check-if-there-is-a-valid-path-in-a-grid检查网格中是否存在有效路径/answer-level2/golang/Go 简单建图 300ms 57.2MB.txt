```go
func hasValidPath(grid [][]int) bool {
    m, n := len(grid)*3, len(grid[0])*3
    newGrid := make([][]bool, m)
    for i := range newGrid {
        newGrid[i] = make([]bool, n)
    }
    for i := range grid {
        for j := range grid[i] {
            x, y := 3*j, 3*i
            newGrid[y+1][x+1] = true
            switch grid[i][j] {
            case 1:
                newGrid[y+1][x] = true
                newGrid[y+1][x+2] = true
            case 2:
                newGrid[y][x+1] = true
                newGrid[y+2][x+1] = true
            case 3:
                newGrid[y+1][x] = true
                newGrid[y+2][x+1] = true
            case 4:
                newGrid[y+1][x+2] = true
                newGrid[y+2][x+1] = true
            case 5:
                newGrid[y+1][x] = true
                newGrid[y][x+1] = true
            case 6:
                newGrid[y][x+1] = true
                newGrid[y+1][x+2] = true
            }
        }
    }
    return dfs(1, 1, m, n, newGrid) // 注意起点
}

func dfs(i, j, m, n int, grid [][]bool) bool {
    if i == m-1 && j == n-2 { // 终点
        return true
    }
    if i < 0 || i >= m || j < 0 || j >= n || !grid[i][j] {
        return false
    }
    grid[i][j] = false
    return dfs(i-1, j, m, n, grid) || dfs(i, j-1, m, n, grid) ||
        dfs(i+1, j, m, n, grid) || dfs(i, j+1, m, n, grid)
}
```