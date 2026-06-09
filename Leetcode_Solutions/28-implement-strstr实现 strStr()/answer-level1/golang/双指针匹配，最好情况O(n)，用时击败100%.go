### 解题思路
保存和匹配字符串首字母相同的索引，避免暴力解法

### 代码

```golang
func strStr(haystack string, needle string) int {
	i := 0
	j := 0
	z := 0
	var index []int
	for i < len(haystack) && j < len(needle) {
		if haystack[i] == needle[0] {
			index = append(index, i)
		}
		if haystack[i] == needle[j] {
			j++
		} else {
			if z < len(index)-1 {
					z++
					i = index[z]
					j = 1
				}else {
					j = 0
				}

		}
		i++
	}
	if j == len(needle) {
		return i - j
	}
	return -1

}
```