### 解题思路
先找到最短的元素，因为最长公共前缀的长度肯定小于等于这个元素的长度
接着遍历最短的元素，和数组中的每个元素的相同位置比较看是否相同
如果遇到不同的了，那就返回不同的之前的所有元素
如果遍历完了这个最短元素，说明这个最短元素就是最长公共前缀，直接返回

### 代码

```golang
func longestCommonPrefix(strs []string) string {
	// 最长的公共前缀的长度肯定小于等于数组中最短的元素
	// 所以从这个元素开始当基准
	short := findShortestInArray(strs)
	// 早发现早治疗
	if len(short) == 0 {
	    return ""
    }
	// 遍历这个最短的每个位置元素，用来判断是不是相等
	for i, v := range short {
		// 要判断多少次，取决于数组strs中有多少个元素，所以用的len(strs)
		for j := 0; j < len(strs); j++ {
			// 数组的第j个元素的第i个位置不等于我们的short的第i个位置的元素
			// 写成strs[j][i] 是为了和short里面的每个元素一一对应比较
			if strs[j][i] != byte(v) {
				// 到了第[j][i]个没有匹配上，那么就说明之前的都匹配上了，所以直接返回[j][:i]
				return strs[j][:i]
			}
		}
	}
	// 遍历完short了，说明short就是最长的，直接返回
	return short
}

func findShortestInArray(s []string) string {
	// 空字符数组返回空
	if len(s) == 0 {
		return ""
	}
	// 临时定义最短为数组第一个
	shortest := s[0]
	// 遍历数组每个元素
	for _, v := range s {
		// 找到当前小于res
		if len(v) < len(shortest) {
			// 看看是否是空的，空的说明数组中有空字符，所以最长公共前缀肯定为空
			if len(v) == 0 {
				return ""
			}
			// 替换当前最小为当前遍历到的元素
			shortest = v
		}
	}
	return shortest
}

```