```
func strStr(haystack string, needle string) int {
    if len(needle) == 0 {
		return 0
	}

	if len(needle) == 1 {
		for i, h := range haystack {
			if needle == string(h) {
				return i
			}
		}
		return -1
	}

	start := -1
	i := 0
	j := 0
	for i < len(haystack) && j < len(needle) {
		if needle[j] == haystack[i] && j == 0 {
			start = i
			i++
			j++
			continue
		}

		if needle[j] != haystack[i] {
			if start != -1 {
				i = start
			}
			start = -1
			j = 0
		} else {
			if j == len(needle)-1 && start != -1 {
				return start
			}
			j++
		}
		i++
	}

	return -1
}
```