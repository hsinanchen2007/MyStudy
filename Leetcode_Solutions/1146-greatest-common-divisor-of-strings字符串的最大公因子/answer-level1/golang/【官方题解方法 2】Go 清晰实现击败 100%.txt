官方题解 2 基于这样的事实：

如果 S 是 s1 和 s2 的最大公因串，那么 `S = s1[:gcd(len(s1), len(s2))]`。 另附一个枚举法实现。
```go []
func gcdOfStrings(str1 string, str2 string) string {
	G := gcd(len(str1), len(str2)) // 最大公约数
	S := str1[:G]                  // 最大公因子 串

	if check(str1, S) && check(str2, S) { // 如果 S 能同时填充 str1 和 str2, 那么则为所求
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

// 求完整 t 能否多次填满 s
func check(s, t string) bool {
	for strings.HasSuffix(s, t) {
		s = s[len(t):]
	}

	return s == ""
}
```
```go []
// 枚举法
func gcdOfStrings0(str1 string, str2 string) string {
	if len(str1) < len(str2) {
		return gcdOfStrings0(str2, str1)
	}

	var j int

	for i := 1; i < len(str2); i++ {
		s := str2[:i]
		if check(str1, s) && check(str2, s) {
			j = i
		}
	}

	return str2[:j]
}

// 求完整 t 能否多次填满 s
func check(s, t string) bool {
	for strings.HasSuffix(s, t) {
		s = s[len(t):]
	}

	return s == ""
}
```