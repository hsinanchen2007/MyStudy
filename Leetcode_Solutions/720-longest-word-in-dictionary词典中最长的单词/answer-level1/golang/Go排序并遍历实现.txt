首先用标准库对字典排序，然后遍历数组，将所有前缀字符串用map保存，最后得到长度最长且前缀存在于map中的字符串。

```
执行用时 : 20 ms, 在Longest Word in Dictionary的Go提交中击败了100.00% 的用户
内存消耗 : 6.2 MB, 在Longest Word in Dictionary的Go提交中击败了75.00% 的用户
```
```Go []
func longestWord(words []string) string {
	if len(words) == 0 {
		return ""
	} else if len(words) == 1 {
		if len(words[0]) > 1 {
			return ""
		}
		return words[0]
	}
	sort.Strings(words)
	longest := ""
	last := ""
	set := make(map[string]int)
	for i := range words {
		if len(words[i]) == 1 {
			if longest == "" {
				longest = words[i]
			}
			last = words[i]
			set[last] = 0
		} else if words[i][0:len(words[i])-1] == last {
			if len(words[i]) > len(longest) {
				longest = words[i]
			}
			last = words[i]
			set[last] = 0
		} else if _, ok := set[words[i][0:len(words[i])-1]]; ok {
			last = words[i]
			set[last] = 0
		}
	}
	return longest
}