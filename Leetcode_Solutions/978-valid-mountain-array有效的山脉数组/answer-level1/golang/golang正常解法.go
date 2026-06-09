```
func validMountainArray(A []int) bool {
	if len(A) < 3 {
		return false
	}
	var max_temp_idx int = 0
	// 找到第一个比后面元素大的下标,该下标之前的子数组是一个升序数组,
	// 注意,这里获取到的最大值前面必须有元素,也就是说,不能是第一个元素
	for i := 0; i < len(A) - 1; i++ {
		if A[i] > A[i + 1] {
			if i == 0 {
				return false
			}
			max_temp_idx = i
			break
		}
	}
	for i := max_temp_idx; i < len(A) - 1; i++ {
		// 山峰右边不是降序,返回false
		if A[i] <= A[i+1] {
			return false
		}
	}
	if max_temp_idx > 0 && max_temp_idx < len(A) - 1 {
		return true
	}
	return false
}
```

时间复杂度为 O(n)
空间复杂度为 O(1)