### 解题思路
此处撰写解题思路

### 代码

```golang
func wiggleMaxLength(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	const (
		being = 0
		up    = 1
		down  = 2
	)
	state := being
	result := 1
	for i := 1; i < len(nums); i++ {
		switch state {
		case being:
			if nums[i-1] > nums[i] {
				result++
				state = down
			} else if nums[i-1] < nums[i] {
				result++
				state = up
			}
		case up:
			if nums[i-1] > nums[i] {
				state = down
				result++
			}
		case down:
			if nums[i-1] < nums[i] {
				state = up
				result++
			}
		}

	}
	return result
}

```