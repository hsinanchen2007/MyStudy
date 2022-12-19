### 解题思路
此处撰写解题思路

### 代码

```golang
func fairCandySwap(A []int, B []int) []int {
	sumA:=0
	sumB:=0
	mapA:=make(map[int]int)
	mapB:=make(map[int]int)
	for i:=0;i< len(A);i++{
		mapA[A[i]]++
		sumA+=A[i]
	}
	for i:=0;i< len(B);i++{
		mapB[B[i]]++
		sumB+=B[i]
	}
	N:=sumA-sumB
	for k,_:=range mapA{
		if _,ok:=mapB[k-N/2];ok{
			return []int{k,k-N/2}
		}
	}
	return nil
}
```