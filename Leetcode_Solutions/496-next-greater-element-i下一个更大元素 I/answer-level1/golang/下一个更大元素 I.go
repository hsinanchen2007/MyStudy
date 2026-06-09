### 解题思路
单调栈, 哈希表

### 代码 

```golang
func nextGreaterElement(nums1 []int, nums2 []int) []int {
	length := len(nums2)
	bigger := make(map[int]int, len(nums1))
	for _, n := range nums1 {
		bigger[n] = -1
	}
	stack := make([]int, 0, length)
	for i := length - 1; i >= 0; i-- {
		n := nums2[i]
		if _, ok := bigger[n]; ok {
			for len(stack) > 0 && stack[len(stack)-1] <= n {
				stack = stack[:len(stack)-1]
			}
			if len(stack) > 0 {
				bigger[n] = stack[len(stack)-1]
			}
		}
		stack = append(stack, n)
	}
	result := make([]int, len(nums1))
	for i := 0; i < len(result); i++ {
		result[i] = bigger[nums1[i]]
	}
	return result
}
```