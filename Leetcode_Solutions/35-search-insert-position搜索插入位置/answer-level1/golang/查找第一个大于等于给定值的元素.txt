##### 这样写应该好理解一些，4 ms, 93.08%, 3.1 MB, 55.66%
```
//查找第一个大于等于给定值的元素
func searchInsert(nums []int, target int) int {
	n := len(nums)

	//特判，比如 [1,3,5,6], 7
	if target > nums[n-1] {
		return n
	}

	left := 0
	right := n - 1
	for left <= right {
		mid := left + (right-left)/2
		//如果mid的值小于要查找的值，那么要查找的值肯定在mid右边，所以更新left
		if nums[mid] < target {
			left = mid + 1
		} else {
			//nums[mid] >= target
			//如果mid的值大于等于要查找的值，并且mid是数组的第一个元素
			//或者mid的前一个元素小于要查找的值，说明找到，返回mid
			//否则，要查找的元素在mid左边，所以更新right
			if mid == 0 || nums[mid-1] < target {
				return mid
			}
			right = mid - 1
		}
	}
	return -1
}
```