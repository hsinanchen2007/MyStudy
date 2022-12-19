59/59 cases passed (0 ms)
Your runtime beats 100 % of golang submissions
Your memory usage beats 100 % of golang submissions (2.3 MB)

func merge(nums1 []int, m int, nums2 []int, n int)  {
	idx1 := m - 1
	idx2 := n - 1

	idx := m + n - 1
	for idx1 >= 0 && idx2 >= 0 {
		if nums1[idx1] < nums2[idx2] {
			nums1[idx] = nums2[idx2]
			idx2--
		} else {
			nums1[idx] = nums1[idx1]
			idx1--
		}
		idx--
	}

	if idx1 < 0 {
		for i := idx2; i >= 0; i-- {
			nums1[i] = nums2[i]
		}
	}
}