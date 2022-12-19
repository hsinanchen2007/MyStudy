首先找到最短串，然后用cursor按index对比

```
func longestCommonPrefix(strs []string) string {
	lenStrs := len(strs)
	// 边界判断
	if lenStrs == 0 {
		return ""
	}
	// 找到最短元素长度和索引
	var minLen, minStrIndex = len(strs[0]), 0
	for i := 1; i < lenStrs; i++ {
		curLen := len(strs[i])
		if curLen < minLen {
			minLen = curLen
			minStrIndex = i
		}
	}
	// 最短元素
	minLenStr := strs[minStrIndex]
	var cursor int
	Flag:
	for ; cursor < minLen; cursor++ {
		for j := 0; j < lenStrs; j++ {
			if strs[j][cursor] != minLenStr[cursor] {
				break Flag
			}
		}
	}
	return minLenStr[:cursor]

}
```


![image.png](https://pic.leetcode-cn.com/3887cb9d94a2708b8a7e2b370adc72dd2f58094e1e9372913463ed3b76e2b7e2-image.png)
