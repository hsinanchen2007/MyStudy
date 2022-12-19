往新数组里不断比较放入，数组满的时候就取到了中位数,一共要比较(m+n)/2 次 所以时间复杂度是满足的？


```
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    n1l := len(nums1)
	n2l := len(nums2)
	tl := n1l + n2l
	htl := tl / 2
	sum := make([]int, 0, htl+1)
	step1 := 1
	step2 := 1
	index1 := 0
	index2 := 0
	var min *int
	targetStep := &step1
	target := nums1
	for {
		if index1 == n1l {
			target = nums2
			for len(sum) != cap(sum) {
				sum = append(sum,target[index2])
				index2++
			}
		}
		if index2 == n2l {
			target = nums1
			for len(sum) != cap(sum) {
				sum = append(sum,target[index1])
				index1++
			}
		}
		if len(sum) == cap(sum) {
			break
		}

		if nums1[index1] > nums2[index2] {
			min = &index2
			target = nums2
			targetStep = &step2
		}else {
			min = &index1
			target = nums1
		}
		sum = append(sum,target[*min])
		*min+=*targetStep
	}
	if tl%2 != 0 {
		return float64(sum[htl])
	}
	return float64(sum[htl] + sum[htl-1]) / 2
}


```
