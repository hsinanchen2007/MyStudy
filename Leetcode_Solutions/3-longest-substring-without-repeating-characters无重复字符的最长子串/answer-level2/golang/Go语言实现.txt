step1: 参数检查

step2: 遍历字符串

step2.1: 判断当前位置和下一个位置是否相等


step2.2: 判断下一个位置是否已经在set集合中
```
type void struct{}

var member void

func lengthOfLongestSubstring(s string) int {
	if s == "" {
		return 0
	}
	longest := 1
	for i := 0; i < len(s); i++ {
		set := make(map[string]void) // New empty set
		set[string(s[i])] = member
		for j := i; j < len(s)-1; j++ {
			if string(s[j]) == string(s[j+1]) {
				break
			} else {
				_, exists := set[string(s[j+1])]
				if !exists {
					set[string(s[j+1])] = member
					if j-i+2 > longest {
						longest = j - i + 2
					}
				} else {
					break
				}
			}
		}
	}
	return longest
}
```