### 解题思路
此处撰写解题思路

### 代码

```golang
func largestSumAfterKNegations(A []int, K int) int {
	for K>0{
		sort.Ints(A)
		A[0]=-A[0]
        K--
	}
	res:=0
	for _,v := range A{
		res+=v
	}
	return res
}
```