```
func contains(bytes []byte, char byte) bool {
	for _, v := range bytes {
		if v == char {
			return true
		}
	}
	return false
}

func remove(bytes []byte, char byte) (result []byte) {
	for _, v := range bytes {
		if v == char {
			continue
		} else {
			result = append(result, v)
		}
	}
	return
}

func lengthOfLongestSubstring(s string) int {
	var set []byte
	max := 0
	for i, j := 0, 0; j < len(s); {
		if set == nil || !contains(set, s[j]) {
			set = append(set, s[j]);j++
			if max < j-i {
				max = j - i
			}
		} else {
			set = remove(set, s[i]);i++
		}
	}
	return max
}
```
