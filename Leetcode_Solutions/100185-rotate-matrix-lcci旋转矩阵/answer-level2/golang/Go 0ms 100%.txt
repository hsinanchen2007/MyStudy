### 解题思路
先对matrix转置（只需对主对角线下半区域与主对角线对称位置交换即可）,再对matrix按行逆序

### 代码

```golang
func rotate(matrix [][]int)  {
	// matrix 转置
	for i:=0;i<len(matrix);i++{
		for j:=0;j<i;j++{
			matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
		}
	}
	// matrix 按行逆序
	for i:=0;i<len(matrix);i++{
		for j:=0;j<len(matrix[i])/2;j++{
			matrix[i][j],matrix[i][len(matrix[i])-1-j] = matrix[i][len(matrix[i])-1-j],matrix[i][j]
		}
	}
}
```