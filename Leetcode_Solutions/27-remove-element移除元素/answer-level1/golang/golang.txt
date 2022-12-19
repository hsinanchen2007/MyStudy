```
func removeElement(nums []int, val int) int {
   var res int
	i := 0
	for i < len(nums) {
		if nums[i] != val {
			nums[res] = nums[i]
			res++
		}
		i++
	}

	return res
}
```