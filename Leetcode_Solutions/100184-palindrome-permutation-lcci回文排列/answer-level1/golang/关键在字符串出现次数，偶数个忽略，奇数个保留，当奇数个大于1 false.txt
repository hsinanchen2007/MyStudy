```
func canPermutePalindrome(s string) bool {
	keyCount := map[rune]bool{}
	for _, item := range s {
		if _, ok := keyCount[item]; !ok {
			keyCount[item] = true
		} else {
			delete(keyCount, item)
		}
	}
	return len(keyCount) <= 1
}
```