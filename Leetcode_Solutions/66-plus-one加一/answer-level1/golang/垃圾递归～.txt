```go
func plusOne(digits []int) []int {

	var res = make([]int, len(digits)+1)

	res[0] = plusDigits(res, digits, 0)

	if res[0] == 0 {
		return res[1:]
	} else {
		return res
	}
}

 func plusDigits(res []int, digits []int, index int) int {
	if index == len(digits)-1 {
		result := digits[index] + 1
		if result > 9 {
			result = result - 10
			res[index+1] = result
			return 1
		} else {
			res[index+1] = result
			return 0
		}
	}

	curResult := digits[index] + plusDigits(res, digits, index+1)
	if curResult > 9 {
		curResult = curResult - 10
		res[index+1] = curResult
		return 1
	} else {
		res[index+1] = curResult
		return 0
	}
}

```
