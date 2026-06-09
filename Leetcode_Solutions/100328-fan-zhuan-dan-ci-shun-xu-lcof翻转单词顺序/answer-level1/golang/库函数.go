### 解题思路
学俩库函数

### 代码

```golang
func reverseWords(s string) string {
	parts := strings.Split(s, " ")
	size := len(parts)
	var rparts[] string
	for i := size-1; i >= 0; i-- {
		if parts[i] != ""{
			rparts = append(rparts, parts[i])
		}
	}
	return strings.Join(rparts, " ")
}
```