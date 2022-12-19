### 解题思路
此处撰写解题思路

### 代码

```golang
func transpose(A [][]int) [][]int {
	if len(A)==0{
		return nil
	}
	res:=make([][]int,0, len(A[0]))
	for j:=0;j< len(A[0]);j++{
		tmp:=make([]int,0)
		for i:=0;i< len(A);i++{
			tmp= append(tmp, A[i][j])
		}
		res= append(res, tmp)
	}
	return res
}
```