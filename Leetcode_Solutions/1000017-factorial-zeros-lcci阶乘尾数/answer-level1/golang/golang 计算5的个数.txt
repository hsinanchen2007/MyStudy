```
func trailingZeroes(n int) int {
    count := 0
	for i := 5; i <= n; i *= 5 {
		count += n/i
	}
	return count
}
```
