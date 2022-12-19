### 解题思路
此处撰写解题思路
元素类型是byte 不是int
先 遍历 矩阵的每一个元素，查找它的最大矩阵，当 子矩阵的 长度 突破记录的时候，更新到 变量k
查找 每个元素的子矩阵的时候，就是 查找 该元素为 顶点的 长度为d的 正方形，当正方形内的所有元素 都为 '1的时候，继续扩大 子矩阵 的边长，当遇到0 的时候 返回，并更新d到k，如果 d>k的话，然后 继续遍历矩阵的其他点，继续找 最大子矩阵

### 代码

```golang
func maximalSquare(matrix [][]byte) int {
	k:=0
	row:= len(matrix)
	cols:=0
	if row>0{
		cols = len(matrix[0])
	}

	for i:=0;i<row;i++{
		for j:=0;j<cols;j++{
			if matrix[i][j]=='1'{
				d:=1
				flag:=true
				B:
				for (i+d)<row&&(j+d)<cols&&flag{
					for p:=i;p<=(i+d);p++{
						for q:=j;q<=(j+d);q++{
							if matrix[p][q]=='0'{
								flag=false
								goto B
							}
						}
					}
					d++
				}
				if d>k{
					k=d
				}
			}
		}
	}
	return k*k
}
```