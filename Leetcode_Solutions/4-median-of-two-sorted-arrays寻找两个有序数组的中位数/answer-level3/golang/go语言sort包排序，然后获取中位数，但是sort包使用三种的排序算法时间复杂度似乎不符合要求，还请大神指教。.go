func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var to []int
	var f float64
	to=append(to,nums1...)
	to=append(to,nums2...)
	sort.Ints(to)//直接调用sort包排序
	if len(to)%2==0 {//判断奇偶数区分中位数
        f= (float64(to[len(to)/2-1]) + float64(to[len(to)/2]))/2
	}else {
		f= float64(to[(len(to)-1)/2])
	}
	return f
}