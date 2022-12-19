既然是两个有序数组，采用归并的思想
如果两个数组长度之和为基数，那么找出第(len+1)/2个元素
如果两个数组长度之和为偶数，那么分别找出第len/2和len/2 + 1和元素，然后除以2

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	len1 := len(nums1)
	len2 := len(nums2)

	len := len1 + len2

	var index1, index2 int
	var a, b int
	for index1 < len1 || index2 < len2 {
		tmp := 0
		if index1 < len1 && index2 < len2{
			if nums1[index1] < nums2[index2]{
				tmp = nums1[index1]
				index1++
			} else {
				tmp = nums2[index2]
				index2++
			}
		} else if index1 < len1{
			tmp = nums1[index1]
			index1++
		} else {
			tmp = nums2[index2]
			index2++
		}

		if len % 2 == 0 {
			if index1 + index2 - len/2 == 1 {
				a = tmp
			} else if len/2 == index1 + index2 {
				b = tmp
			}
		} else {
			if index1 + index2 == (len + 1)/2 {
				a = tmp
			}
		}
	}

	if len % 2 == 0 {
		return float64(a+b)/float64(2)
	} else {
		return float64(a)
	}
}