### 解题思路
计算2个字符串的ascii码总和， 如果总和相等，字符串必定相等。

### 代码

```golang
func CheckPermutation(s1 string, s2 string) bool {
if s1 == s2 {
		return true
	}
	s1AscNum := 0
	s2AscNum := 0
	for _, r := range []rune(s1) {
		s1AscNum += int(r)
	}
	for _, r := range []rune(s2) {
		s2AscNum += int(r)
	}
	return s1AscNum == s2AscNum
}
```