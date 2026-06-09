### 解题思路
此处撰写解题思路

### 代码

```golang
func canJump(nums []int) bool {
	length := len(nums)
	index := make([]int, length)

	for i := 0; i < length; i++ {
		index[i] = nums[i] + i
	}
	jump := 0
	maxindex := nums[0]
	for jump < length && jump <= maxindex {
		
		if index[jump] > maxindex {
			maxindex = index[jump]
		}
		jump++
	}
	if jump == length {
		return true
	}
	return false
}

```