### 解题思路
哈希表记录第一遍循环的字符以及次数，第二遍依旧循环入参字符串，查看哈希表中该字符出现的频率是否超过一即可得到结果。

### 代码

```golang
func firstUniqChar(s string) int {
	ht := make(map[rune]int)

	for _, ch := range s {
		ht[ch]++
	}

	for i, ch := range s {
		if ht[ch] > 1 {
			continue
		}
		return i
	}

	return -1
}

```