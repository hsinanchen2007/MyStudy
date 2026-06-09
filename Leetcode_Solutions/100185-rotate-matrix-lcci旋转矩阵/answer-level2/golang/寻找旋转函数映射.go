**思路**

```

1. copy原slice，用于数据来源
2. 映射函数i,j -->> j,length-1-i
3. 讲数据填充原来的slice


注：slice是引用传递，slice的二维数组选择逐个[]int填充
```

**代码**

```
func rotate(matrix [][]int)  {
	var length = len(matrix)
	var copyMatrix = make([][]int,0,length)

	for i:=0;i<length;i++  {
		var temp = make([]int,length,length)
		copy(temp,matrix[i])
		copyMatrix = append(copyMatrix, temp)
	}
	
	for i:=0;i<length;i++  {
		for j:=0;j<length;j++  {
			var index1,index2 = j,length-1-i
			matrix[index1][index2] = copyMatrix[i][j]
		}
	}
}
```
