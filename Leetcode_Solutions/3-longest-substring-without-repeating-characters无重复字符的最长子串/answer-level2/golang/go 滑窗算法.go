### 解题思路
滑窗算法，用一个MAP保存字符最近出现的Index。

第一次提交在刷新left的时候，漏了判断重现字符的index是否超过了当前left，导致"abba"这样的用例left刷回成了1。。。。

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
	if len(s) < 2 {
		return len(s)
	}
	max, leftIdx := 0, 0
	charIdxMap := make(map[uint8]int)

	for i:=0; i<len(s); i++ {
		if idx, ok := charIdxMap[s[i]]; ok {
			if idx >= leftIdx {
				leftIdx = idx+1
			}
		}
		charIdxMap[s[i]] = i
		if i-leftIdx+1 > max {
			max = i-leftIdx+1
		}
	}

	return max
}
```