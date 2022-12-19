```go
func thirdMax(nums []int) int {

	max, secMax, thirdMax := math.MinInt64, math.MinInt64, math.MinInt64
	
	for i := 0; i < len(nums); i++ {
		n := nums[i]
		switch {
		case n == max || n == secMax || n == thirdMax:
		case n > max:
			tmp := max
			max = n
			thirdMax = secMax
			secMax = tmp
		case n > secMax:
			thirdMax = secMax
			secMax = n
		case n > thirdMax:
			thirdMax = n
		}
	}

	if thirdMax > math.MinInt64 {
		return thirdMax
	}

	return max
}
```
