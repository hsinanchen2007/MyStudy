```
func longestConsecutive(nums []int) int {
	if len(nums) == 0 || len(nums) == 1{
		return len(nums)
	}
	max, count := 0, 0
	sort.Ints(nums)

	for i := 0; i< len(nums) - 1; i ++ {
		if nums[i] + 1 == nums[i + 1] {
			count ++
		} else if nums[i] != nums[i + 1]{
			if count > max {
				max = count
			}
			count = 0
		}
	}
	if count > max {
		max = count
	}
	return max + 1
}
```
