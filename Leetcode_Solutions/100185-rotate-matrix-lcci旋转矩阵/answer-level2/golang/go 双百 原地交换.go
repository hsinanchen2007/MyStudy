### 解题思路
规律，数字交换；

### 代码

```golang
func rotate(matrix [][]int)  {
    n := len(matrix[0])
    for i:=0;i<n/2;i++ {

        for j:=i;j<n-1-i;j++{
            //  ->
            matrix[i][j],matrix[j][n-1-i] = matrix[j][n-1-i],matrix[i][j]
            //fmt.Println(matrix)

            //  <-
            matrix[n-1-i][n-1-j],matrix[n-1-j][i] = matrix[n-1-j][i],matrix[n-1-i][n-1-j]
            //fmt.Println(matrix)

            //  XX
            matrix[i][j],matrix[n-1-i][n-1-j] = matrix[n-1-i][n-1-j],matrix[i][j]
            //fmt.Println(matrix)

        }
    }

    //return matrix
}
```