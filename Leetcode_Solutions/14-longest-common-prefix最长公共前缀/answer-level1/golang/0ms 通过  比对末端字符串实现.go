```go
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0{
		return ""
	}
	ans := " "
	minLen := math.MaxInt32
	for _, singleStr := range strs {
		if len(singleStr) < minLen {
			minLen = len(singleStr)
		}
	}
	for size := 0; size < minLen; size++ {
		for _, s := range strs {
			if s[size] != strs[0][size] {
				return ans[1:len(ans)-1]  // 一旦发现不匹配之前的最长公共前缀,则返回前缀
			} else {
				if s[size] == ans[len(ans)-1] && size < len(ans)-1{ // 用于应对连续字母组成的字符串,"aa" ,"aa","aa"
					continue
				}
				ans += string(s[size])
			}
		}
	}
	return ans[1:]
}
```
