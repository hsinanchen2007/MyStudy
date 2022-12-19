```
func gcdOfStrings(str1 string, str2 string) string {
	candidateLen := gcd(len(str1), len(str2))
	candidate := str1[0:candidateLen]
	if str1 + str2 == str2 + str1 {
		return candidate
	}
	return ""
}

func gcd(x, y int) int {
	tmp := x % y
	if tmp > 0 {
		return gcd(y, tmp)
	} else {
		return y
	}
}
```
