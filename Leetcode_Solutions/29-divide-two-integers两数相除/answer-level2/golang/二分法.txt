二分法求除数，不停的二分找被除数的中间值*除数，看是否大于被除数，大于的话，再中间值的左边，小于等于在右边或者相等，断开的递归的条件需要注意，因为可能有余数，所以start >= end 的时候需要判断一下start值*除数是否 <= 被除数，如果大于的话，则是start-1
```
func divide(dividend int, divisor int) int {
	if dividend == 0 {
		return 0
	}
	absDicidend := math.Abs(float64(dividend))
	absDivisor := math.Abs(float64(divisor))
	prefix := 1
	if (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) {
		prefix = -1
	}
	if absDicidend == absDivisor {
		return prefix * 1
	} else if absDicidend < absDivisor {
		return 0
	}
	r := 0
	if int(absDivisor) == 1 {
		r = int(absDicidend)
	} else {
		r = half(0, int(absDicidend), int(absDicidend), int(absDivisor))
	}
	r = r * prefix
	if r == 2147483648 {
		r--
	}
	return r
}

func half(start int, end int, dividend int, divisor int) int {
	if start >= end {
		if start*divisor <= dividend {
			return start
		}
		return start - 1
	}
	r := 0
	mid := start + (end-start)>>1
	if mid*divisor <= dividend {
		r = half(mid+1, end, dividend, divisor)
	} else {
		r = half(start, mid-1, dividend, divisor)
	}
	return r
}
```
