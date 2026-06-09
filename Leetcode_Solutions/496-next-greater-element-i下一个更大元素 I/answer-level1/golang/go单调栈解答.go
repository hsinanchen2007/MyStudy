### 解题思路
使用单调栈

### 代码

```golang
func nextGreaterElement(nums1 []int, nums2 []int) []int {
	hashMap := make(map[int]int)
	stack := make([]int, 0, 0)
	sl := 0
	result := make([]int, 0, len(nums1))
	for i := 0; i < len(nums2); i++ {
		if 0 == sl || nums2[stack[sl-1]] > nums2[i] {
			stack = append(stack, i)
			sl++
		} else {
			for sl != 0 && nums2[stack[sl-1]] <= nums2[i] {
				topIndex := stack[sl-1]
				hashMap[nums2[topIndex]] = nums2[i]
				stack = stack[:sl-1]
				sl--
			}
			stack = append(stack, i)
            sl++
		}
	}
	for _, num := range nums1 {
		v, ok := hashMap[num]
		if ok {
			result = append(result, v)
		} else {
			result = append(result, -1)
		}
	}
	return result
}
```