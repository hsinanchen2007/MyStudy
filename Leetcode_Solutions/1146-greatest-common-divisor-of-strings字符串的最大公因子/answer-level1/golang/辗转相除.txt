### 解题思路
此处撰写解题思路

### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {
	G := gcd(len(str1), len(str2))
	S := str1[:G]

	if check(str1, S) && check(str2, S) {
		return S
	}

	return ""
}

// 辗转相除
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}

	return a
}

func check(s, t string) bool {
	for strings.HasSuffix(s, t) {
		s = s[len(t):]
	}

	return s == ""
}
```