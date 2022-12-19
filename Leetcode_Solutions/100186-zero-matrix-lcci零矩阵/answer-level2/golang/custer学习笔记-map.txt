### 解题思路
使用map记录要清0的行和列

### 代码

```golang
func setZeroes(matrix [][]int) {
  row := make(map[int]bool)
  column := make(map[int]bool)
  m, n := len(matrix), len(matrix[0])
  for i := 0; i < m; i++ {
    for j := 0; j < n; j++ {
      if matrix[i][j] == 0 {
        row[i] = true // 第几行清0
        column[j] = true // 第几列清0
      }
    }
  }
  for i := 0; i < m; i++ {
    for j := 0; j < n; j++ {
      if _, ok := row[i]; ok {
        matrix[i][j] = 0
      }     
      if _, ok := column[j]; ok {
        matrix[i][j] = 0
      } 
    }
  }
}
```