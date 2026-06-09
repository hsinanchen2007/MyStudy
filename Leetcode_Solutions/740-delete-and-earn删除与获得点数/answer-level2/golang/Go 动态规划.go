
```
func deleteAndEarn(nums []int) int {
	if len(nums) == 0 || nums == nil {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	length := findmax(nums)
	nums1 := make([]int, length+1)
	for _, i := range nums {
		nums1[i]++
	}
	return rob(nums1)
}

func findmax(nums []int) int {
	max := 0
	for _, v := range nums {
		if v > max {
			max = v
		}
	}
	return max
}

func rob(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	dps := make([]int, len(nums)+1)
	dps[0] = 0
	dps[1] = nums[0]
	for i := 2; i <= len(nums); i++ {
		dps[i] = int(math.Max(float64(dps[i-1]), float64(dps[i-2]+nums[i-1]*(i-1))))
	}
	return dps[len(nums)]
}
```
