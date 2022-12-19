遍历字符串，判断当前字符在后面的位置索引，出现的位置不相同则说明不是同构字符串。
```
执行用时 : 4 ms, 在Isomorphic Strings的Go提交中击败了98.92% 的用户
内存消耗 : 2.7 MB, 在Isomorphic Strings的Go提交中击败了77.08% 的用户
```
```go []
func isIsomorphic(s string, t string) bool {
	for i := 0; i < len(s); i++ {
		if strings.Index(s[i+1:], s[i:i+1]) != strings.Index(t[i+1:], t[i:i+1]) {
			return false
		}
	}
	return true
}