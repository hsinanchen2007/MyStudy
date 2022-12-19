### 解题思路

### 代码

```golang
func find132pattern(nums []int) bool {
	if len(nums) == 0 {
		return false
	}
	l := len(nums)
	third := -2147483647
	var arr []int
	for i := l - 1; i >= 0; i-- {
		if nums[i] < third {
			return true
		}
		for len(arr) > 0 && arr[0] < nums[i] {
			if nums[i] > third {
				third = arr[0]
			}
			arr = arr[1:]
		}
		arr = append([]int{nums[i]}, arr...)
	}
	return false
}
```