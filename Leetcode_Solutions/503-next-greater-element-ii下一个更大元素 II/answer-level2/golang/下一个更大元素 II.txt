### 解题思路
找出最大值, 做一次循环移动将最大值移到数组末尾, 然后按照常规方法解决.

### 代码

```golang
func nextGreaterElements(nums []int) []int {
	if len(nums) <= 0 {
		return nil
	}
	max := nums[0]
	maxIdx := 0
	result := make([]int, len(nums))

	for i, num := range nums {
		if num >= max {
			max = num
			maxIdx = i
		}
		// 结果数组
		result[i] = -1
	}

	if maxIdx < len(nums)-1 {
		tailLen := len(nums) - maxIdx - 1
		tails := make([]int, tailLen)
		for i := maxIdx + 1; i < len(nums); i++ {
			tails[i-maxIdx-1] = nums[i]
		}
		for i := maxIdx; i >= 0; i-- {
			nums[i+tailLen] = nums[i]
		}
		for i := tailLen - 1; i >= 0; i-- {
			nums[i] = tails[i]
		}
	}
	stack := make([]int, 0, len(nums))
	ri := maxIdx
	for i := len(nums) - 1; i >= 0; i-- {
		for len(stack) > 0 && stack[len(stack)-1] <= nums[i] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) > 0 {
			result[(ri+len(nums)) % len(nums)] = stack[len(stack)-1]
		}
		stack = append(stack, nums[i])
		ri--
	}

	return result

}

```