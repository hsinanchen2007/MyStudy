```
func rotate(nums []int, k int) {
	var (
		i, val, count int
		currIdx       = 0
		length        = len(nums)
	)
	if length == 0 {
		return
	}

	for i = 0; i < (k%length) && count < length; i++ {
		currIdx = i
		val = nums[i]
		for {
			currIdx = (currIdx + k) % length
			val, nums[currIdx] = nums[currIdx], val
			count++
			if currIdx == i {
				break
			}
		}
	}
}
```
