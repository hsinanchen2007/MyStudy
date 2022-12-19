```
func plusOne(digits []int) []int {

	for i := len(digits) - 1; i >= 0; i-- {
		tmp := digits[i] + 1

		if tmp == 10 {

			if i == 0 {
				digits[i] = 0
				result := []int{1}
				result = append(result,digits...)
				return  result
			}
			 digits[i]=0
			 continue
		}
		digits[i] = tmp
		break
	}
	return digits
}

```
