func merge(nums1 []int, m int, nums2 []int, n int) {
	first := m - 1
	second := n - 1
	for first >= 0 && second >= 0 {
		if nums1[first] < nums2[second] {
			nums1[first+second+1] = nums2[second]
			second--
		} else {
			nums1[first+second+1] = nums1[first]
			first--
		}
	}
	for second >= 0 {
		nums1[second] = nums2[second]
		second--
	}
}
