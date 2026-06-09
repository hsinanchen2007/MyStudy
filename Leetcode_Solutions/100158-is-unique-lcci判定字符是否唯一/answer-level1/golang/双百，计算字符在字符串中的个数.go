
用了strings包
```
func isUnique(astr string) bool {
	for i := 0; i < len(astr); i++ {
		if strings.Count(astr, string(astr[i])) > 1 {
			return false
		}
	}
	return true
}
```
自己写一个函数调用
```
func isUnique(astr string) bool {
	for i := 0; i < len(astr); i++ {
		if stringCount(astr, astr[i]) > 1 {
			return false
		}
	}
	return true
}
func stringCount(s string, t byte) int {
	ret := 0
	for i := 0; i < len(s); i++ {
		if s[i] == t {
			ret++
		}
	}
	return ret
}

```
