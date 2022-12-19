```go
func merge(nums1 []int, m int, nums2 []int, n int)  {
	index := len(nums1) - m - n

	if m == 0 {
		copy(nums1[index:], nums2)
		return
	}

	if n == 0 {
		return
	}

	if nums1[index] < nums2[index] {
		merge(nums1[index+1:], m-1, nums2[index:], n)
	} else {
		copy(nums1[index+1:m+1], nums1[index:m])
		nums1[index] = nums2[index]
		merge(nums1[index+1:], m, nums2[index+1:], n-1)
	}
}


```
