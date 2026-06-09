```
func reverseString(s []byte) {
	n := len(s)
	if n == 1 || n == 0 {
		return
	}

	i := 0
	j := n - 1
	for ; i < n/2; i++ {
		s[i], s[j] = s[j], s[i]
		j--
	}
}
```