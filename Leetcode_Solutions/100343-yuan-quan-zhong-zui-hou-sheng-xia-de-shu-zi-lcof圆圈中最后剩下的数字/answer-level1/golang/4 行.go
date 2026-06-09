```
func lastRemaining(n int, m int) (rst int) {
	for i := 2; i <= n; i++ {
		rst = (rst + m) % i
	}
	return
}
```
