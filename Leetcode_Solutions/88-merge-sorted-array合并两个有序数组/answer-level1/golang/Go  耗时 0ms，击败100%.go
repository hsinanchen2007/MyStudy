```golang []
func reverse(nums []int) {
	head,tail := 0,len(nums)-1
	for head < tail {
		nums[head],nums[tail] = nums[tail],nums[head]
		head++
		tail--
	}
}

func merge(nums1 []int, m int, nums2 []int, n int)  {
	j := 0
	for i := 0;i < len(nums1); i++{
		if j < n {
			if nums1[i] > nums2[j] {
				reverse(nums1[i:])    // 如果数组1的该下标大于数组2的下标，则将数组1的i以后的元素向后平移一下
				reverse(nums1[i+1:])  // 平移采用的是两次反转
				nums1[i] = nums2[j]   // 将数组1的下标赋值为数组2的值
				j++
			}
		}
	}
	for _,v := range nums2[j:]{ // 数组2还没遍历完，把数组2接到数组1后面
		nums1[m+j] = v
		j ++
	}
}
```
