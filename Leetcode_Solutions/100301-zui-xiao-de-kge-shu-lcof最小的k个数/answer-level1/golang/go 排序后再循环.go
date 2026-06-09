```
func getLeastNumbers(arr []int, k int) []int {
	sort.Ints(arr[:])
	nums := make([]int, k)
	for i := 0; i < k; i++ {
		nums[i] = arr[i]
	}
	return nums
}
```
