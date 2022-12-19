```

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	commonPrefix := strs[0]
	for _, itemStr := range strs {
			commonLen := len(commonPrefix)
			itemLen := len(itemStr)
			if itemLen == 0 {  // 存在空的字符串 则公共前缀一定是空
				return ""
			}
			commonIndex := 0
			for i := 0; i < commonLen; i++ { // 最大遍历次数不超过公共前缀

				if i >= itemLen /*遍历已经到字符串末尾*/|| itemStr[i] != commonPrefix[i]/*碰到第一个不相等到字符*/ {
					break
				}
				commonIndex++
			}
			commonPrefix = commonPrefix[:commonIndex]
	}
	return commonPrefix
}
```
