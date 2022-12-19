```
func merge(nums1 []int, m int, nums2 []int, n int) {
	total := n + m
	for n > 0 && m > 0 {
		if nums1[m-1] > nums2[n-1] {
			nums1[total-1] = nums1[m-1]
			m--
		} else {
			nums1[total-1] = nums2[n-1]
			n--
		}
		total--
	}
	for n > 0 {
		nums1[total-1] = nums2[n-1]
		n--
		total--
	}
}
```
