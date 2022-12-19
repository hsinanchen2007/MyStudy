``` go
func largestSumAfterKNegations(A []int, K int) int {
	sort.Ints(A)
	for i := 0; i < K; i++ {
		A[0] = -A[0]
		sort.Ints(A)
	}
	count := 0
	for _, v := range A {
		count = count + v
	}
	return count
}
```
