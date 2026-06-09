唯一要注意的点就是 "a " 这个 test case...

```
func lengthOfLastWord(s string) (length int) {
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == ' ' {
			if length == 0 {
				continue
			}
			return length
		}
		length++
	}
	return length
}
```
