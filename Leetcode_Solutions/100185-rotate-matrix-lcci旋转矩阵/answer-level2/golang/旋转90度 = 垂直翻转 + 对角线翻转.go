### 解题思路
* 旋转90度 = 垂直翻转 + 对角线翻转

### 代码

```golang
func rotate(matrix [][]int)  {
  N := len(matrix)
  // 垂直翻转
  for i:=0;i<N/2;i++{
    for j:=0;j<N;j++{
      matrix[i][j],matrix[N-i-1][j] = matrix[N-i-1][j],matrix[i][j]
    }
  }
  //fmt.Println(matrix)
  // 斜对角线翻转
  for i:=0;i<2*N-1;i++{
    for j:=0;j<(i+1)/2;j++{
      if j >= N || i-j>=N  {continue}
      matrix[j][i-j],matrix[i-j][j] = matrix[i-j][j],matrix[j][i-j]
    }
  }
  //fmt.Println(matrix)
}


```