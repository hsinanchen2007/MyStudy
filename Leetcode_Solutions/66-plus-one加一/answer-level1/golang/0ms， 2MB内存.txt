### 完整代码
```
func plusOne(digits []int) []int {
    if len(digits) == 0 {
		return digits
	}
	isCarry := 0
	digitsLen := len(digits)
	result := make([]int, digitsLen + 1, digitsLen + 1) // 避免污染入参，从新开辟一段内存
	for i := 0; i < digitsLen; i++ {
		result[i + 1] = digits[i]
	}
	result[ digitsLen ] = result [ digitsLen ] + 1
	for k := digitsLen ; k > 0 ; k-- {
		currentVal := result[k] + isCarry
		isCarry = 0
		if currentVal < 10 {
			result[k] = currentVal
			break
		} else {
			currentVal -= 10
			result[k] = currentVal
			isCarry = 1
			if k == 1 {
				result[0] = 1
			}
		}
	}
	if result[0] == 0 {
		return  result[1:]
	}
	return result
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/003f47447fe77cde5c878232788af2f32c1d2c354149e3c70a9fabb8bbe60865-image.png)
