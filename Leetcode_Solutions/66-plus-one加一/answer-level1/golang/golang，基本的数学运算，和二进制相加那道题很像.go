```golang
func plusOne(digits []int) []int {
	size := len(digits)
	if size == 0 {
		return digits
	}

	for i := size - 1; i >= 0; i-- {
		if digits[i] >= 0 && digits[i] < 9 {
			digits[i]++
			return digits
		} else {
			digits[i] = 0
		}
	}
	return append([]int{1}, digits...)
}
```
