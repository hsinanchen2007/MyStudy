### 解题思路
最小值数组

### 代码

```golang
func find132pattern(nums []int) bool {
	length := len(nums)
    if length <= 0 {
        return false
    }
	// minArr[i]等于nums[0...i]的最小值
	minArr := make([]int, length, length)
	min := nums[0]
	for i, num := range nums {
		if min > num {
			min = num
		}
		minArr[i] = min
	}
	// stack 用于维护132模式中的2
	stack := make([]int, 0, length)
	for i := length - 1; i > 0; i-- {
		max := nums[i]
		min = minArr[i]

		// 寻找1*2模式,
		// 因为min已经是nums[0...i]的最小元素, 那么小于min的栈顶元素肯定也不会大于nums[0...i-1]的最小元素
		// 因此弹出栈顶元素
		for len(stack) > 0 && stack[len(stack)-1] <= min {
			stack = stack[0 : len(stack)-1]
		}
		// 判断是否符合32模式
		if len(stack) > 0 && max > stack[len(stack)-1] {
			return true
		}
		stack = append(stack, max)
	}
	return false
}

```