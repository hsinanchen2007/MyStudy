```go
func isPalindrome(x int) bool {
	ret := 0
	if (x < 0) || (x%10 == 0 && x != 0) {
		return false
	} else {
		for x > ret {
			pop := x % 10
			x /= 10
			ret = ret*10 + pop
		}
		if x == ret || x == ret/10 {
			return true
		} else {
			return false
		}
	}
}
```

