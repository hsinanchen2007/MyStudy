### 解题思路
此处撰写解题思路

### 代码

```golang
func smallestRangeI(A []int, K int) int {
	if len(A)==0{
		return 0
	}
	max:=A[0]
	min:=A[0]
	for i:=0;i< len(A);i++{
		if max<A[i]{
			max=A[i]
		}
		if min >A[i]{
			min=A[i]
		}
	}
	if max-min>2*K{
		return max-min-2*K
	}
	return 0
}
```