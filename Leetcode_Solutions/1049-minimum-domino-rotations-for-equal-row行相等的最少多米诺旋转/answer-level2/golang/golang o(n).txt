计算1-6的个数，如果A[i] == B[i] 只要记录一次

如果某个num的个数等于len(A),说明可以达到目的。然后判断是旋转A还是旋转B就行。
```
func minDominoRotations(A []int, B []int) int {
	nums := [7]int{}
	as := [7]int{}
	bs := [7]int{}
	for i := 0; i < len(A); i++ {
		if A[i] == B[i] {
			nums[A[i]]++
		} else {
			nums[A[i]]++
			as[A[i]]++
			nums[B[i]]++
			bs[B[i]]++
		}
	}
	for k, v := range nums {
		if v == len(A) {
			return min(as[k], bs[k])
		}
	}
	return -1
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}


```
