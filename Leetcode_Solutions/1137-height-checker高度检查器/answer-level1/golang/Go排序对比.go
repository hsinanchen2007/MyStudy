先对数组排序再统计出排序后的数组与原数组不同的元素个数。

```go []
func heightChecker(heights []int) int {
	sorted := make([]int, len(heights))
	copy(sorted, heights)
	sort.Ints(sorted)
	cnt := 0
	for i := range sorted {
		if sorted[i] != heights[i] {
			cnt++
		}
	}
	return cnt
}
