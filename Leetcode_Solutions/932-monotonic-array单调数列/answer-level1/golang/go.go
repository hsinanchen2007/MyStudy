### 解题思路
此处撰写解题思路

### 代码

```golang
func isMonotonic(A []int) bool {
	
	for len(A)>=2&&A[0]==A[1]{
		A=A[1:]
	}
	if len(A)==1{
		return true
	}
	if A[0]<A[1]{
		for len(A)>1&&A[0]<=A[1]{
			A=A[1:]
		}
		if len(A)>1{
			return false
		}
	}else{
		for len(A)>1&&A[0]>=A[1]{
			A=A[1:]
		}
		if len(A)>1{
			return false
		}
	}
	return true
}
```