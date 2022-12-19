借鉴解答区的大佬的思路，位移的方式计算。

go版本：

```go [go]
func divide(dividend int, divisor int) int {
	if dividend == 0 || divisor == 0 {
		return 0
	}

	if divisor == 1 {
		return dividend
	}

	maxInt := 1<<31

	if dividend == maxInt-1 && divisor == -1 {
		return maxInt-1
	}
	isMinus := (dividend < 0 && divisor >0 )|| (dividend > 0 && divisor < 0 )

	var (
		ds =  divisor
		dd = dividend
	)
	
	if ds < 0 {
		ds = -ds
	}

	if dd < 0 {
		dd = -dd
	}

	var result int
	for i := 31; i >= 0; i-- {
        it := uint(i)
		if dd >> it >= ds {
			result += 1<<it
			dd -= ds<<it
		}
	}

	if isMinus {
		result = -result
	}

	if result > maxInt-1 {
		result = maxInt-1
	}

	return result
}
```