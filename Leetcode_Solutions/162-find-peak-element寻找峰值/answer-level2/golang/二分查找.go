二分查找，如果mid的左右恰好小于mid值，直接返回，如果不小于，则判断，mid是否小于mid+1，满足的话，则满足了峰值的半个条件，则往右移区间，不满足，则说明mid > mid+1（相邻的两个数不相等，题目有说明），峰值在mid的左边或者是他本身，往左移，因为题目说-1和n是负无穷，所以当找到0或者n-1的时候，说明这个值就是其中一个峰值。（因为有可能有别的峰值在其他区间，但是没往那个区间去找，当时的mid值只满足一个方向）
```
func findPeakElement(nums []int) int {
	if len(nums) == 1 {
		return 0
	}
	left := 0
	right := len(nums)-1
	mid := left + (right-left)>>1
	for left <= right {
		mid = left + (right-left)>>1
		if mid > 0 && mid < len(nums)-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1] {
			return mid
		} else if mid < len(nums)-1 && nums[mid] < nums[mid+1] {
			left = mid+1
		} else if mid == len(nums)-1 || mid == 0 {
			return mid
		}else {
			right = mid
		}
	}
	return mid
}
```
