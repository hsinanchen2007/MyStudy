```go []
func numWays(n int) int {

	a, b := 1, 1

	for i := 1; i < n; i++ {
		a, b = b, a+b

		if b > 1000000007 {
			b = b % 1000000007
		}
	}

	return b

}
```
