```go
func rotate(matrix [][]int)  {
    n := len(matrix)

    if n == 0 {
        return
    }

    for i := (n>>1)-1; i >= 0; i-- {
        for j := (n-1)>>1; j >= 0; j-- {
            matrix[i][j], matrix[j][n-i-1] =  matrix[j][n-i-1],matrix[i][j]
            matrix[i][j], matrix[n-i-1][n-j-1] =  matrix[n-i-1][n-j-1],matrix[i][j]
            matrix[i][j], matrix[n-j-1][i] =  matrix[n-j-1][i],matrix[i][j]
        }
    }
}
```