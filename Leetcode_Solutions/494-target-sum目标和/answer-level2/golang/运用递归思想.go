运用递归枚举

```golang []
func findTargetSumWays(nums []int, S int) int {
    if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		if nums[0] == 0 && S == 0{
			return 2
		}
		if nums[0] == S || 0-nums[0] == S{
			return 1
		}
	}
	num := nums[0]
	nums = nums[1:]
	return findTargetSumWays(nums, S - num) + findTargetSumWays(nums, S + num)
}
```
