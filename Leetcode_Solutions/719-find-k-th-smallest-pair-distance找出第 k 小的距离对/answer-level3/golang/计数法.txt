//计数，对数组排序，分配一个最大差值大小的数组，然后记录所有差值一样的个数，最后个数相加到大于k的时候，第k个就是对应数组的index
```
func smallestDistancePair(nums []int, k int) int {
	sort.Ints(nums)
	r := make([]int, nums[len(nums) - 1] - nums[0] + 1)
	for i := 0; i < len(nums); i++ {
		vi := nums[i]
		for j := i + 1; j < len(nums); j++ {
			vj := nums[j]
			m := int(math.Abs(float64(vj - vi)))
			r[m]++
		}
	}
	count := 0
	for idx,v := range r {
		count+=v
		if count >= k {
			return idx
		}
	}
	return 0
}
```
