### 解题思路
此处撰写解题思路
层层替换，每次替换只需要替换4个值
### 代码

```golang
func rotate(matrix [][]int)  {
    n := len(matrix)
    roud := n/2
    for i:=0; i<roud; i++ {
        for j:=i; j<(n-i*2-1)+i; j++ {
            tmp1 := matrix[i][j]
            matrix[i][j] = matrix[n-j-1][i]
            tmp2 := matrix[j][n-i-1]
            matrix[j][n-i-1] = tmp1
            tmp3 := matrix[n-i-1][n-j-1]
            matrix[n-i-1][n-j-1] = tmp2
            matrix[n-j-1][i] = tmp3
        }
    }
}
```