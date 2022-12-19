### 解题思路
此处撰写解题思路

### 代码

```golang
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	if len(strs) == 1 {
		return strs[0]
	}
	s1 := strs[0]
	index := 1
	for index <= len(s1) {
		for _, str := range strs {
			if !strings.HasPrefix(str,string(s1[:index])) {
				return string(s1[:index-1])
			}
		}
		index ++
	}
	return string(s1[:index-1])
}
```