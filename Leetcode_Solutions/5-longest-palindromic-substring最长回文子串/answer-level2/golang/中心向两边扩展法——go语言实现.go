```
import (
	"strings"
)

func longestPalindrome(s string) string {
	if s == "" {
		return ""
	}
	s = getHelpString(s)
	longest := 1
	res := ""
	for i := 0; i < len(s); i++ {
		left := i - 1
		right := i + 1
		length := 1
		for left >= 0 && right < len(s) {
			if string(s[left]) == string(s[right]) {
				length += 2
				if length > longest{
					longest = length
					res = s[left:right+1]
				}
				left--
				right++
			}else {
				break
			}
		}
	}
	return strings.Replace(res, "#", "", -1)
}

func getHelpString(s string) string {
	if s == "" {
		return ""
	}
	res := "#"
	for i := 0; i < len(s); i++ {
		res += string(s[i]) + "#"
	}
	return res
}
```