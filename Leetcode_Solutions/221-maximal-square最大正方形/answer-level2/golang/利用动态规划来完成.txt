### 解题思路
此处撰写解题思路

### 代码

```golang
// 利用动态规划  构造一个一样大的二维数组  然后对连续1的个数进行统计  找最大值即可
func maximalSquare(matrix [][]byte) (res int) {
	h := len(matrix)
	switch h {
	case 0:
	default:
		w := len(matrix[0])
		switch w {
		case 0:
		default:
			var makeArr func(l1,l2 int) [][]int
			makeArr = func(l1, l2 int) [][]int {
				arr := make([][]int,l1)
				for i:=0;i<l1;i++{
					arr[i] = make([]int,l2)
				}
				return arr
			}
			dp := makeArr(h+1,w+1)
			for i:=1;i<=h;i++{
				for j:=1;j<=w;j++{
					if matrix[i-1][j-1] == '1'{
						dp[i][j] = minFunc(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1
						if res < dp[i][j]*dp[i][j]{
							res = dp[i][j]*dp[i][j]
						}
					}
				}
			}
		}
	}
	return res
}

func minFunc(a... int) int  {
	min := a[0]
	for i:=1;i<len(a);i++{
		if min>a[i]{
			min = a[i]
		}
	}
	return min
}


```