![image.png](https://pic.leetcode-cn.com/28a22207a1bda667390d5c8777f48488a2490a3b532a7a3cc89c601af4c3e9a1-image.png)


```
func longestCommonPrefix(strs []string) string {
	strNumber := len(strs)

	//测试空切片
	if strNumber == 0 {
		return ""
	}

	//取得最小的字符串长度,即最大可能的公共前缀长度
	maxPreLength := len(strs[0])
	for x := 1; x < strNumber; x++ {
		strLength := len(strs[x])
		if strLength < maxPreLength {
			if strLength == 0 {
				//存在空字符串
				return ""
			}
			maxPreLength = strLength
		}
	}

	//获取相同部分的长度
	i := 0
I:
	for ; i < maxPreLength; i++ {
		for j := 1; j < strNumber; j++ {
			if strs[j][i] != strs[j-1][i] {
				break I
			}
		}
	}

	return strs[0][0:i]
}
```
