### 解题思路
此处撰写解题思路

### 代码

```golang
func largestPerimeter(A []int) int {
    sort.Ints(A)
	for i:= len(A)-1;i>=2;i--{
		if A[i-1]+A[i-2]>A[i]{
			return A[i]+A[i-1]+A[i-2]
		}
	}
	return 0
}
```