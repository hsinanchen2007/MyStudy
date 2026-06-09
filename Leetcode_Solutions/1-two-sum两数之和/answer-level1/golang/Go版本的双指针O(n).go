```
func twoSum(nums []int, target int) []int {
	temp := make([]int, len(nums))
	copy(temp, nums)
	sort.Ints(nums)
	i := 0
	j := len(nums) - 1
	for i < j {
		if nums[i]+nums[j] == target {
			break
		} else if nums[i]+nums[j] < target {
			i++
		} else {
			j--
		}
	}

	fi, fj := false, false
	for k, v := range temp {
		if !fi && v == nums[i] {
			i = k
			fi = true
		} else if !fj && v == nums[j] {
			j = k
			fj = true
		}
	}

	return []int{i, j}
}
```
