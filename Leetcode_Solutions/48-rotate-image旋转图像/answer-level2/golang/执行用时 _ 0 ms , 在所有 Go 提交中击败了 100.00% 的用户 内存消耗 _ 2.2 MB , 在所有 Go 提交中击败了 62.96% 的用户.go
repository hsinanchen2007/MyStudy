最蠢写法，每次转动外面一层，再去里面一层
```
func rotate(matrix [][]int)  {
	if len(matrix)<=1 {
		return
	}
	m,n:=0,len(matrix)-1
	temp:=make([]int,n-m+1)
	for m<n{
		for i:=m; i<=n; i++ {
			temp[i]=matrix[m][i]
		}
		//先换四个角
		point:=matrix[m][n]
		matrix[m][n]=matrix[m][m]
		matrix[m][m]=matrix[n][m]
		matrix[n][m]=matrix[n][n]
		matrix[n][n]=point
		//再换边
		for i:=m+1; i<n; i++ {
			//t:=matrix[m][m+n-i]
			matrix[m][m+n-i]=matrix[i][m]
			matrix[i][m]=matrix[n][i]
			matrix[n][i]=matrix[m+n-i][n]
			matrix[m+n-i][n]=temp[m+n-i]
			//matrix[n-i][n]=t
		}
		//fmt.Println(matrix)
		m++
		n--
	}
}
```
