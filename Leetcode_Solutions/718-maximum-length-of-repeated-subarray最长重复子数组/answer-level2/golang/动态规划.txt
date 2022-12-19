### 解题思路
此处撰写解题思路

### 代码

```golang
func findLength(A []int, B []int) int {
	res:=0
	dp:=make([][]int, len(A)+1)
	for i:=0;i< len(dp);i++{
		x:=make([]int, len(B)+1)
		dp[i]=x
	}
	for i:=1;i<= len(A);i++{
		for j:=1;j<= len(B);j++{
			if A[i-1]==B[j-1]{
				dp[i][j]=dp[i-1][j-1]+1
			}
			if dp[i][j]>res{
				res=dp[i][j]
			}
		}
	}
	return res
}
```