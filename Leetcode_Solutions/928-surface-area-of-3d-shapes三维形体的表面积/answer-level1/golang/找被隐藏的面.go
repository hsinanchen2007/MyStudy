### 解题思路
* 直接算外表面比较复杂，通过算重合被隐藏的面比较简单
  * 上下隐藏 2 *（grid[i][j] - 1 ）
  * 左右隐藏 min(grid[i][j],前后左右)

### 代码

```golang
func surfaceArea(grid [][]int) int {
  N := len(grid)
  sum := 0
  for i:=0;  i< N; i++{
    for j:=0; j<N ; j++{
      if grid[i][j] == 0 {continue}
      sum += 6 + ( grid[i][j] - 1 ) * 4
      if i - 1 >= 0 {
        minV := min(grid[i-1][j],grid[i][j])
        sum -= minV
      }
      if i+1 <N{
        minV := min(grid[i+1][j],grid[i][j])
        sum -= minV
      }
      if j - 1 >= 0 {
        minV := min(grid[i][j-1],grid[i][j])
        sum -= minV
      }
      if j+1 <N{
        minV := min(grid[i][j+1],grid[i][j])
        sum -= minV
      }
    }
  }
  return sum
}


func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```