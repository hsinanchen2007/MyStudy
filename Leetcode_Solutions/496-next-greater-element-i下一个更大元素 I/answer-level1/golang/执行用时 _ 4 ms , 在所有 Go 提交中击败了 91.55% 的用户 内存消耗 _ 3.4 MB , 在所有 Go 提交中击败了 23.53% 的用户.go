```
func nextGreaterElement(nums1 []int, nums2 []int) []int {
	var stack []int
	var mp = make(map[int]int)
	for i := 0; i < len(nums2); i++ {

		//如果栈为空直接放入栈
		if len(stack) == 0 {
			stack = append(stack, nums2[i])
			continue
		}

		//当前的和栈一个个比对
		for {
			if len(stack) == 0 {
				break
			}
			if nums2[i] > stack[len(stack)-1] {
				mp[stack[len(stack)-1]] = nums2[i]
				stack = stack[:len(stack)-1]
				continue
			} else {
				break
			}
		}
		stack = append(stack, nums2[i])

	}
	for {
		if len(stack) == 0 {
			break
		}
		mp[stack[len(stack)-1]] = -1
		stack = stack[:len(stack)-1]
	}

	var r []int
	for i := 0; i < len(nums1); i++ {
		m, _ := mp[nums1[i]]
		r = append(r, m)
	}

	return r
}
```
