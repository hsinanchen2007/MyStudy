### 解题思路
此处撰写解题思路

### 代码

```golang
func findNumberIn2DArray(matrix [][]int, target int) bool {
    if len(matrix)==0 {
        return false
    }
    for i:=0;i<len(matrix);i++ {
        for j:=0;j<len(matrix[i]);j++ {
            if matrix[i][j]==target {
                return true
            }
        }
    }
    return false
}
```