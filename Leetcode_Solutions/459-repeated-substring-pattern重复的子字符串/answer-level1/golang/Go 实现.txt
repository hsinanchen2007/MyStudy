从索引0开始循环检查字符串，把0至当前索引的字符串作为子串，判断后面的部分是否由该子串组成。

```
执行用时 : 8 ms, 在Repeated Substring Pattern的Go提交中击败了100.00% 的用户
内存消耗 : 5.1 MB, 在Repeated Substring Pattern的Go提交中击败了86.67% 的用户
```
```Go []
func repeatedSubstringPattern(s string) bool {
	var pattern bool
	for i := 0; i < len(s)/2+1; i++ {
		if i > 0 && len(s)%i != 0 {
			continue
		}
		pattern = true
		for j := i; j < len(s); j = j + i {
			if j+i > len(s) || s[0:i] != s[j:j+i] || i == 0 {
				pattern = false
				break
			}
		}
		if pattern {
			return true
		}
	}
	return false
}