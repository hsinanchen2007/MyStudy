```
func plusOne(digits []int) []int {
	for i := len(digits) - 1; i >= 0; i-- {
		if 9 != digits[i] {
			digits[i]++
			return digits
		} else {
			digits[i] = 0
		}
	}

	var arr = make([]int, len(digits)+1, len(digits)+1)
	arr[0] = 1
	return arr
}
```