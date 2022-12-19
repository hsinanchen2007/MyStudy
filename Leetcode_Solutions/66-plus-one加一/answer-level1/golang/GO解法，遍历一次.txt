```
func plusOne(digits []int) []int {
	var pre = 1 // 标识进位，有进位为1，无进位为0
	for i := len(digits)-1; i >= 0; i-- {
		pre = (digits[i] + pre) / 10
		if pre == 0 {
			digits[i] = digits[i] + 1
			break
		}
		if pre == 1 {
			digits[i] = 0
		}
	}
    
	if pre == 0 {
		return digits
	}

	var res = []int{1} // len=1, cap=1
	return append(res, digits...)
	
}
```