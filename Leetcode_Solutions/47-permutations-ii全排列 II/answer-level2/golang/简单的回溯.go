相比较于 No46，在这道题只需要加上一个判重条件即可：

```
func permuteUnique(nums []int) (final [][]int) {
	backtrace2(len(nums), 0, nums, &final)

	return final
}

func backtrace2(n, first int, nums []int, output *[][]int) {
	if n == first {
		*output = append(*output, append([]int(nil), nums...))
	}

	visited := map[int]bool{}
	for i := first; i < n; i++ {
		if visited[nums[i]] {
			continue
		}
		visited[nums[i]] = true
		nums[i], nums[first] = nums[first], nums[i]
		backtrace2(n, first+1, nums, output)
		nums[i], nums[first] = nums[first], nums[i]
	}
}
```
