### 解题思路
双向遍历

### 代码

```golang
func isPalindrome(s string) bool {
	if len(s) == 0{
		return true
	}
	j := 0
	s = strings.ToLower(s)
	for i := len(s)-1; i>=j;{
		if unicode.IsDigit(rune(s[i])) || unicode.IsLetter(rune(s[i])){
			if unicode.IsDigit(rune(s[j])) || unicode.IsLetter(rune(s[j])){
				if s[i] != s[j] {
					return false
				}
			}else{
				j += 1
				continue
			}
		}else{
			i -=1
			continue
		}
		i -=1
		j +=1
	}
	return true
}
```