```
func findRepeatNumber(nums []int) int {

	mp := map[int]int{}

	for i := 0 ; i < len(nums) ; i++{
		mp[nums[i]] ++
		if mp[nums[i]] > 1{
			return nums[i]
		}
	}
	return 0
}
```
