### 解题思路
通过二分查找

### 代码

```golang
func searchInsert(nums []int, target int) int {
	var res int
	begin := 0
	end := len(nums) - 1
	for begin <= end {
		mid := (begin + end) / 2
		if nums[mid] == target {
			res = mid
			return res
		} else if nums[mid] > target {
			if mid == 0 || nums[mid-1] < target {
				res = mid
				return res
			}
			end = mid - 1
		} else if nums[mid] < target {
			if mid == len(nums)-1 || nums[mid+1] > target {
				res = mid + 1
				return res
			}
			begin = mid + 1
		}
	}
	return res
}

```