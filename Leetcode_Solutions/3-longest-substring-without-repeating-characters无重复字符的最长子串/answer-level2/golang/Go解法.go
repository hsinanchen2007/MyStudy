### 解题思路
先定义一个变量maxLen放最大字串的长度，
再定义一个slice放字符。

遍历s，存到slice中，如果slice中有重复的，计算下当前的slice长度，与变量maxLen比较，如果大于则覆盖，再将重复字符之前的值，从slice中移除。
最后还需比较slice和maxLen的大小。

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
	maxLen := 0
	sSlice := make([]int32, 0, len(s))
	for _, v := range s {
		for x, y := range sSlice {
			if y == v {
				if len(sSlice) > maxLen {
					maxLen = len(sSlice)
				}
				sSlice = sSlice[x+1:]
				break
			}
		}
		sSlice = append(sSlice, v)
	}
	if len(sSlice)>maxLen{
		return len(sSlice)
	}
	return maxLen
}
```