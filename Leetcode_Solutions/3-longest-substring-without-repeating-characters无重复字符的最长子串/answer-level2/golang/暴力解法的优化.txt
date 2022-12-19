### 解题思路
此处撰写解题思路

### 代码

```golang
// 暴力解法的优化：减少遍历次数
// 当i=0，遍历到abca时，退出第一次循环，此时j=3；
// 当i=1时，j从3开始就行，因为之前的都比较过了，同时sub去除前一个值
func lengthOfLongestSubstring2(s string) int {
	if len(s) <= 0 {
		return 0
	}
	max := s[0:1]
	i, j := 0, 1
	// 默认值为第一个字符
	sub := s[0:1]
	for ; i < len(s); i++ {
		if i > 0 {
			// 如果长度等于1，说明i，j相同，后移一位；否则从sub中删除i
			if len(sub) > 1 {
				sub = sub[1:]
			} else {
				sub = s[i : i+1]
			}
		}
		// 确保j要比i大，否则会同时向前aab
		if j < i+1 {
			j = i + 1
		}
		for ; j < len(s); j++ {
			flag := true
			for x := 0; x < len(sub); x++ {
				if s[j] == sub[x] {
					flag = false
					break
				}
			}
			if !flag {
				break
			}
			sub = s[i : j+1]
			if len(sub) > len(max) {
				max = sub
			}
		}
	}
	return len(max)
}

```