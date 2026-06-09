### 解题思路
二分查找分别查找左右边界  时间复杂度 2(log2N)依然是log2N

注意细节
```go
if mid == 0 || nums[mid-1] < target {
				res = mid
				return res //注意要提前退出
			}
	right = mid-1		//如果mid是边界会在上面返回的，所以这里不是边界，即左边还有相同的target元素，所以这里是mid-1
```
### 代码

```golang

func searchRange(nums []int, target int) []int {
	left := left_bound(nums, target)
	right := right_bound(nums, target)
	return []int{left, right}
}
func left_bound(nums []int, target int) int {
	res := -1
	left := 0
	right := len(nums) - 1
	for left <= right {
		mid := (left + right) / 2
		if nums[mid] == target {
			if mid == 0 || nums[mid-1] < target {
				res = mid
				return res //注意要提前退出
			}
			right = mid-1
		} else if target > nums[mid] {
			left = mid + 1
		} else if target < nums[mid] {
			right = mid - 1
		}
	}
	return res
}
func right_bound(nums []int, target int) int {
	res := -1
	left := 0
	right := len(nums) - 1
	for left <= right {
		mid := (left + right) / 2
		if nums[mid] == target {
			if mid == len(nums)-1 || nums[mid+1] > target {
				res = mid
				return res //注意要提前退出
			}
			left=mid+1
		} else if target > nums[mid] {
			left = mid + 1
		} else if target < nums[mid] {
			right = mid - 1
		}
	}
	return res
}

```