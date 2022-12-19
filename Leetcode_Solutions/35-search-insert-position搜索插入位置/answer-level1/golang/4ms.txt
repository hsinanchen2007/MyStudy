### 解题思路
二分查找法

### 代码

```golang
func searchInsert(nums []int, target int) int {
	// 二分查找法
	left, right := 0, len(nums)
	for left < right {
		mid := left + (right - left) >> 1
		if nums[mid] == target {
			return mid
		}
		if nums[mid] < target {
			left++
		}
		if nums[mid] > target {
			right--
		}
	}
	return left
}
```