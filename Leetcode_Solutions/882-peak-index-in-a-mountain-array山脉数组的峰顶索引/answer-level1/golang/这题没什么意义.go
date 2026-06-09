### 解题思路
此处撰写解题思路

### 代码

```golang
func peakIndexInMountainArray(A []int) int {
	index:=0
	for i:=0;i< len(A)-1;i++{
		if A[i]<A[i+1]{
			index=i+1
		}else{
			break
		}
	}
	return index
}
```