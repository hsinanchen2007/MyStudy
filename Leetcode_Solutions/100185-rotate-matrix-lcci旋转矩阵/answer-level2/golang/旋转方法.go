### 解题思路
此处撰写解题思路

### 代码

```golang

func swap(a ,b *int ){
	tmp := *a
	*a = *b
	*b = tmp
}
func rotate(matrix [][]int)  {
	//找好旋转方式
	/*
	[i,j] - > [j, n-j-1]
	[j,n-j-1] - > [n-i-1, n-j-i]
	[n-i-1, n-j-i] - > [n-j-1,i]
	*/
	n := len(matrix)
	if n < 2{
		return
	}
	r := (n>>1)-1
	c := (n-1)>>1
	for i:= r; i >=0 ; {
		for j:=c ;j >=0;{
			swap(&matrix[i][j], &matrix[j][n-i-1])
			swap(&matrix[i][j], &matrix[n-i-1][n-j-1])
			swap(&matrix[i][j], &matrix[n-j-1][i])
			j-=1
		}
		i -=1
	}
}
```