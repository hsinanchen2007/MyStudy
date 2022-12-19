```
func singleNumber(nums []int) (rst int) {
	for _, num := range nums[1:] {
		nums[0] ^= num
	}
	return nums[0]
}
```
