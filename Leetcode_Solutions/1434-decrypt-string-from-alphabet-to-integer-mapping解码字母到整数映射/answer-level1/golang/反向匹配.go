### 解题思路
反向匹配

### 代码

```golang
func freqAlphabets(s string) string {
	var newStr string
	for i := len(s) - 1; i >= 0; i-- {
		u := s[i]
		if u == '#' {
			sid := s[i-2 : i]
			i -= 2
			sidInt, _ := strconv.Atoi(sid)
			newStr = string(byte(sidInt+97-1)) + newStr
		} else {
			newStr = string(byte(u+48)) + newStr
		}
	}
	return newStr
}
```