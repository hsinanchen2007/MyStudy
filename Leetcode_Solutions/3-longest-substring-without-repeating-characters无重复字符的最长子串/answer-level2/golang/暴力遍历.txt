### 解题思路
从第一个字符开始，找符合的字串（每增加一个字符需要和之前的进行比较）

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
	if len(s) <= 0 {
		return 0
	}
	if len(s) <= 1 {
		return 1
	}
	max := s[0:1]
	for i := 0; i < len(s); i++ {
		sub := s[i : i+1]
		for j := i + 1; j < len(s); j++ {
			flag := true
			for x := 0; x < len(sub); x++ {
				flag = flag && s[j] != sub[x]
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