由于数字都在1-n之间，那么必然对于每一个数字来说数组中都有一个位置使得数组值等于下标 a[i] == i + 1
那么对于a[i] != i+1 的通过交换，将他们放到相应的位置，如果说对应的位置和换过来的数字 是一样的话， 必然是重复数字

```
func findDuplicate(nums []int) int {

	if len(nums) < 2 {
		return 0
	}

	for i := 0; i < len(nums); i ++{

		for nums[i] != i + 1 {
			if nums[i] == nums[nums[i] - 1] {
				return nums[i]
			}
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}
	return 0
}
```