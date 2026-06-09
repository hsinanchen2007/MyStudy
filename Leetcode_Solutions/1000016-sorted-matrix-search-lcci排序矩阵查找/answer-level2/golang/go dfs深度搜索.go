```go
func searchMatrix(matrix [][]int, target int) bool {
    return dfs(matrix, 0, 0, target)
}

func dfs(matrix [][]int, i, j, target int) bool {
    fmt.Println(i, j)
    if i < 0 || i >= len(matrix) {
        return false
    }

    if j < 0 || j >= len(matrix[0]) {
        return false
    }

    if matrix[i][j] == target {
        return true
    }
    if matrix[i][j] == -9 {
        return false
    }

    matrix[i][j] = -9 // 访问过就置为一个不可能的值，防止重复访问。成死循环
    if matrix[i][j] > target {
        return dfs(matrix, i-1, j, target) || dfs(matrix, i, j-1, target)
    }

    return dfs(matrix, i, j+1, target) || dfs(matrix, i+1, j, target)
}
```