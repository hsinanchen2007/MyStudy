调用标准库转换成小写并删除字母数字之外的其他字符，再遍历确认。

```
执行用时 : 4 ms, 在Valid Palindrome的Go提交中击败了97.55% 的用户
内存消耗 : 5.4 MB, 在Valid Palindrome的Go提交中击败了20.00% 的用户
```
```Go []
func isPalindrome(s string) bool {
	a := strings.FieldsFunc(strings.ToLower(s), func(c rune) bool {
		return !unicode.IsLetter(c) && !unicode.IsNumber(c)
	})
	s2 := strings.Join(a, "")
	for i := range s2 {
		if s2[i] != s2[len(s2)-1-i] {
			return false
		}
	}
	return true
}