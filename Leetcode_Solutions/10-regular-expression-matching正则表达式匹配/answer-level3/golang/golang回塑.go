### 解题思路
此处撰写解题思路

### 代码

```golang
func isMatch(s string, p string) bool {
	return _is_match(s, p)
}

func _is_match(s string, p string) bool {
	// terminal
	if len(p) == 0 {
		return len(s) == 0
	}
	first := len(s) != 0 && (s[0] == p[0] || p[0] == '.')
	if len(p) >= 2 && p[1] == '*' {
		// 发现*
		// drill down
		return _is_match(s, p[2:]) || (first && _is_match( s[1:], p))
	} else if first {
		// drill down
		return _is_match( s[1:], p[1:])
	}
	return false
}
```