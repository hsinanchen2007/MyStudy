### 解题思路
改进的二分
首先判断中间值与最右值的大小关系，如果中间值大于最右值，表示最小值在右半边，如果小于则在左半边。等于的情况需要单独判断，因为中间值与最右值相等时，有两种情况，一种是最小值在最左边，即数组是单调不减的，还有一种是在右半边，即单调不减的数组翻转后的结果，因此将右边界缩小。

### 代码

```golang
func findMin(nums []int) int {
	l, r := 0, len(nums)-1
	for m := (l + r) >> 1; l < r; m = (l + r) >> 1 {
		if nums[m] > nums[r] {
			l = m + 1
		} else if nums[m] < nums[r] {
			r = m
		} else {
			r--
		}
	}
	return nums[r]
}
```