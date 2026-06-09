```
func rotate(matrix [][]int)  {
	length := len(matrix)
	for i := 0 ; i < length / 2; i ++{
		for j := i ; j < length - i - 1 ; j ++{
			x,y := i,j
			temp := matrix[x][y]
			for n := 0 ; n < 4 ; n++{
                x,y = y,length - 1 -x
				temp,matrix[x][y] = matrix[x][y],temp
			}
		}
	}
}
```

暴力解法，一层一层的旋转
