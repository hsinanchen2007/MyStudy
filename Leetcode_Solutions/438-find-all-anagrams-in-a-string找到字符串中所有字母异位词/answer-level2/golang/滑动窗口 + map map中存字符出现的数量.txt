### 解题思路
此处撰写解题思路

### 代码

```golang

func findAnagrams(s string, p string) []int {
	var result []int
	var left, right, match int
	tt := []byte(p)
	needs := make(map[byte]int, len(p))
	windows := make(map[byte]int, len(p))
	for _, v := range tt {
		needs[v]++
	}
	for right <= len(s)-1 {
		// 是子串的内容
		if _, ok := needs[s[right]]; ok {
			// 窗口中字符  对应 数加一
			windows[s[right]]++
			// 匹配了某个字符
			if windows[s[right]] == needs[s[right]] {
				match++
			}
		}

		// 全部匹配
		for match == len(needs) {
			// 把长度为 子串的结果 加进去
			if len(p) == right-left+1 {
				result = append(result, left)
			}

			// left边界是子串中的字符，则要计算
			if _, ok := needs[s[left]]; ok {
				// 窗口中字符  对应 数减一
				windows[s[left]]--
				if windows[s[left]] < needs[s[left]] {
					match--
				}
			}
			left++
		}
		right++
	}
	return result
}

```