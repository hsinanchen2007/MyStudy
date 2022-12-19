```
//第一种写法
func searchInsert(nums []int, target int) int {
	index := 0
	for len(nums) >= 1 {
		lens := len(nums)
		midIndex := lens / 2
		if nums[midIndex] == target {
			index += midIndex
			return index
		} else if nums[midIndex] > target {
			nums = nums[:midIndex]
		} else {
			index += len(nums[:midIndex+1])
			nums = nums[midIndex+1:]
		}
	}
	return index
}
//另外一种写法
func searchInsert(nums []int, target int) int {
	start, end := 0, len(nums)-1
	for start <= end {
		mid := (start + end) / 2
		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}
	return start
}
```
