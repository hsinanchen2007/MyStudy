### 解题思路
此处撰写解题思路

### 代码

```golang
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0{
		return ""
	}
	short := strs[0]
	for i:=0; i < len(short); i++ {
		char := short[i]
		for j:=1; j<len(strs);j++  {
			if len(strs[j]) <= i || strs[j][i] != char {
				return short[:i]
			}
		}
	}
	return short
}
```

先默认第一项为最短公共前缀，然后逐个字符与后续所有字符串进行字符比较，当出现不同或者后续字符串字段长度不够时，取从0开始到第i项（因为go中[0:i]不包含i项）即为最长公共前缀