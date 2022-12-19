```
var row, col int

func numIslands(grid [][]byte) int {
    count := 0
    if grid == nil || len(grid) == 0{
        return count
    }
    row, col = len(grid), len(grid[0])
    for i, t := range grid{
        for j, _ := range t{
            if grid[i][j] == '1'{
                numDFS(grid, i, j)
                count++
            }
        }
    }
    return count
}


func numDFS(board [][]byte, i, j int)  {
    if i < 0 || j < 0 || i >= row || j >= col || board[i][j] != '1'{
        return
    }
    board[i][j] = '#'
    numDFS(board, i - 1, j)
    numDFS(board, i + 1, j)
    numDFS(board, i, j - 1)
    numDFS(board, i, j + 1)
}
```
