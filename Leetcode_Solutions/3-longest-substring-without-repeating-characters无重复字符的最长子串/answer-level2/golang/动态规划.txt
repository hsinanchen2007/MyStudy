### 动态规划解题思路
1. 设 max 为不含重复字符的最长子串长度
2. s[i:index] 为 到 s[index]不含重复字符的字符串

- 最优子结构
s[index] 的不含重复字符的最长子串长度 max = Max(max,index+1-i)


### 代码

```golang
func Max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func lengthOfLongestSubstring(s string) int {
	var max int = 0
	var i int = 0

	var maps map[rune]int = make(map[rune]int)
	for index, c := range s {
		c_index, ok := maps[c]
		if ok {
			i = Max(i, c_index+1)
		}

		maps[c] = index
		max = Max(max, index+1-i)
	}

	return max
}


```