golang中Sort.Search函数本身就是二分搜索，但数组需要确保已经排序。

```go
func searchRange(nums []int, target int) []int {

	i := sort.SearchInts(nums, target) // Sort Search 
	if len(nums) == 0 || i == len(nums) || nums[i] != target {
		return []int{-1, -1}
	}

	var j int // 找右边界 
	for j = i; j < len(nums) && nums[i] == nums[j]; j++ {
	}
	if i < len(nums) || nums[i] == target {
		return []int{i, j - 1}
	}
	return []int{-1, -1}

}
```
