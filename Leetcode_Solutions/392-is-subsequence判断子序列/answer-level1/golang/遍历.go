```go
	for i := 0; i < len(t); i++ {
		if len(s) == 0 {
			return true
		}
		if t[i] == s[0] {
			s = s[1:]
		}
	}
	if len(s) > 0 {
		return false
	} else {
		return true
	}
```
