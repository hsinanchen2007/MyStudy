```
func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	} else {
		sub := s[0:1]
		max := 1
		for i := 1; i < len(s); i++ {
			new := s[i : i+1]
			idx := strings.LastIndex(sub, new)
			if idx != -1 {
				sub = sub[idx+1:]
			}
			sub += new
			if max < len(sub) {
				max = len(sub)
			}
		}
		return max
	}
}
```
