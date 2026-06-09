只需要判断slice最后一位元素即可，若不为9，则加1后直接退出；若为9，则向前进一位，当前位改为0，继续下次循环；
待所有元素循环完成后，判断slice首位是否为0，为0则往slice首位插入1代表最高位进位即可。

```golang
func plusOne(digits []int) []int {
	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i] != 9 {
			digits[i]++
			return digits
		} else {
			digits[i] = 0
		}
	}

    // 首位为0，需要最高位插入1代表进位
	if digits[0] == 0 {
		slice := []int{1}
		digits = append(slice, digits...)
	}

	return digits
}
```