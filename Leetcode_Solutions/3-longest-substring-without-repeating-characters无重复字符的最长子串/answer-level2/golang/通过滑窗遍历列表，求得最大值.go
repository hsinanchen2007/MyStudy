```
/*
	滑窗机制，定义一个起始点，遍历字段（结束点不断向后移动）
	设定一个 hash 表用于存放出现过的字符并且记录字符出现的最大的位置
	如果在循环过程中遇到了相同的字符，我们首先得将 hash 表中的字符位置更新到当前的位置
	并且，如果起始点任然在这个重复点之前或者是这个重复点的位置时，则需要将起始点移动到重复元素的后面一个位置
*/

func lengthOfLongestSubstring(s string) int {
	// res 用于记录出现过的最长字段长度
	res := 0
	// startPoint 用于记录先字段的起始点
	startPoint := 0
	tmpMap := map[string]int{}
	for i,v := range strings.Split(s,"") {
		//
		if ii,ok := tmpMap[v];ok {
			tmpMap[v] = i
			if startPoint <= ii {
				startPoint = ii + 1
			}
		} else {
			tmpMap[v] = i
		}
		if i - startPoint + 1 > res {
			res = i - startPoint + 1
		}
	}
	return res
}
```