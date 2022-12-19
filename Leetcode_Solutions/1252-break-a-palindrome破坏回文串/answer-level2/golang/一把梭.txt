```
func breakPalindrome(palindrome string) string {
	var (
		i      int
		length = len(palindrome)
	)
	if length < 2 {
		return ""
	}

	for i = 0; i < length/2; i++ {
		switch palindrome[i] {
		case 'a':
			continue
		default:
			return palindrome[:i] + "a" + palindrome[i+1:]
		}
	}

	return palindrome[:length-1] + "b"
}
```
