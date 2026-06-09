### 解题思路
此处撰写解题思路

### 代码

```golang
func isToeplitzMatrix(matrix [][]int) bool {
    if len(matrix)==1||len(matrix[0])==1{
        return true
    }

    for i:=1;i<len(matrix);i++{
        for j:=1;j<len(matrix[0]);j++{
            if matrix[i][j]!=matrix[i-1][j-1]{
                return false
            }
        }
    }
    return true
}
```