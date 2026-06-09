```
func reverseString(s []byte) {
	for i := range s {
		if i >= len(s)/2 {
			break
		}
		t := s[i]
		s[i] = s[len(s)-1-i]
		s[len(s)-1-i] = t

	}
}
```