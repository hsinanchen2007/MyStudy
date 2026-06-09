### 解题思路
双指针就好了

### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
   C :=make([]int,m+n)
	i:=0
	j:=0
	index:=0
	for i<m && j<n {
		if A[i]<B[j]{
			C[index]=A[i]
			index++
			i++
		}else{
			C[index]=B[j]
			index++
			j++
		}
	}
	if i==m{
		for j<n{
			C[index]=B[j]
			index++
			j++
		}
	}else{
		for i<m {
			C[index] = A[i]
			index++
			i++
		}
	}
	copy(A,C)
}
```