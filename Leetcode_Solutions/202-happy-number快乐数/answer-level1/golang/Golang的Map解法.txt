```
func isHappy(n int) bool {
	calHistory := make(map[int]bool)
	if n <= 0 {
		return false
	}
	for n != 1 {
		if _, ok := calHistory[n]; ok {
			return false
		}
		calHistory[n] = true
		sumTmp := 0
		for n != 0 {
			remain := n%10
			sumTmp += remain * remain
			n /=10
		}
		n = sumTmp
	}
	return true
}
```
