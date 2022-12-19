### 解题思路
设定两端指针low, high，和中间指针 mid := (low+high)/2，然后就是正常的二分操作，左边不存在的话，去右边找，直到返回最终结果，找不到的话，返回 -1.

### 代码

```golang
func search(nums []int, target int) int {
    output := -1
	low, high := 0, len(nums)-1
	for low <= high {
		mid := (low + high) / 2
		if nums[mid] == target {
			output = mid
			return output
		}
		if nums[low] <= nums[mid] {
			if target >= nums[low] && target < nums[mid] {
				high = mid - 1
			} else {
				low = mid + 1
			}
		} else {
			if target > nums[mid] && target <= nums[high] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		}
	}
	return output
}
```