### 解题思路
以第一个字符串作为基准，从第一个字符开始，逐渐增加字符串的长度，判断这些字符串在切片中其他字符串中第一次出现的位置索引是否为 0，当不为 0 时跳出循环，并返回这段字符。
### 代码

```golang
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	var i int
	for ; i < len(strs[0]); i++ {
		flag := 0
		for j := 1; j < len(strs); j++ {
			if strings.Index(strs[j], strs[0][:i+1]) != 0 {
				flag = 1
				break
			}
		}
		if flag!=0 {
			break
		}
	}
	return strs[0][:i]

}
```