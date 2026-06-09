### 解题思路
此处撰写解题思路

### 代码

```golang
func search(nums []int, target int) bool {
    l := 0
	r := len(nums) - 1
	for l < r {
		mid := l + (r-l)/2
		if target == nums[mid] {
			return true
		}
        if nums[mid] == nums[r] {
			r--
			continue
		}
		if (nums[mid] >= nums[r] && (target > nums[mid] || (target < nums[mid] && target <= nums[r]))) ||
			(nums[mid] < nums[r] && target > nums[mid] && target <= nums[r]) {
			l = mid + 1
		} else {
			r = mid
		}
	}
    if l == r && nums[l] == target{
		return true
	}
	return false
}
```