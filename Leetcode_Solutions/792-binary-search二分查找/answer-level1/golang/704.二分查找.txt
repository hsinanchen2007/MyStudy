### 解题思路

真的只是二分查找而已...

### 代码

```golang
func search(nums []int, target int) int {
	l,r,mid := 0,len(nums) - 1,(len(nums) - 1) / 2
	for r >= l {
		if target == nums[mid] {
			return mid
		}else if target > nums[mid] {
			l = mid + 1
		}else {
			r = mid - 1
		}
		mid = (l + r) / 2
	}
	return -1
}
```