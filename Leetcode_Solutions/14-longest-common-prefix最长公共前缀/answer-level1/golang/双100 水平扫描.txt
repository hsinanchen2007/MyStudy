### 解题思路
1设置一个步数的，比较所有列的步数是否相等

### 代码

```golang
func longestCommonPrefix(strs []string) string {
	l := len(strs)
	if l == 0 {return ""}
	if l == 1 {return strs[0]}
	apl := [26]bool{}
	sep := 0
	for ; sep < len(strs[0]); sep++ {
		apl[strs[0][sep]-'a'] = true
		for i := 1; i < l; i++ {
			if sep >= len(strs[i]) || !apl[strs[i][sep]-'a'] {
				return strs[0][:sep]
			}
		}
		apl[strs[0][sep]-'a'] = false
	}
	if sep > 0 {
		return strs[0]
	}
	return ""
}
```