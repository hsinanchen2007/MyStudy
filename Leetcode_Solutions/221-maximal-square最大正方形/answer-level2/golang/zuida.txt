### 解题思路
此处撰写解题思路

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


func maximalSquare(matrix [][]byte) int {
	row := len(matrix)
	cols :=0
	if row>0{
		cols= len(matrix[0])
	}
	max := 0.0
	dp:=[][]float64{}
	var makeArr func(l1,l2 int) [][]float64
	makeArr = func(l1, l2 int) [][]float64 {
		arr := make([][]float64,l1)
		for i:=0;i<l1;i++{
			arr[i] = make([]float64,l2)
		}
		return arr
	}
	dp = makeArr(row,cols)

	for i := 0; i < row; i++ {
		if matrix[i][0] == '1' {
			dp[i][0], max = 1, 1
		}
	}
	for j := 0; j < cols; j++ {
		if matrix[0][j] == '1' {
			dp[0][j], max = 1, 1
		}
	}
	for i := 1; i < row; i++ {
		for j := 1; j < cols; j++ {
			if matrix[i][j] == '1' {
				dp[i][j] = math.Min(dp[i-1][j],math.Min(dp[i][j-1], dp[i-1][j-1]))+1//min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
			}
			if dp[i][j] > max {
				max = dp[i][j]
			}
		}
	}
	return int(max * max)
}
```