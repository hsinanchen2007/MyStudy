### 解题思路
此处撰写解题思路

### 代码

```golang
func flipAndInvertImage(A [][]int) [][]int {
	for i:=0;i< len(A);i++{
		tmp:=[]int{}
		for j:=len(A[i])-1;j>=0 ;j--{
			tmp=append(tmp,A[i][j]^1)
		}
		A[i]=tmp
	}
	return A
}
```