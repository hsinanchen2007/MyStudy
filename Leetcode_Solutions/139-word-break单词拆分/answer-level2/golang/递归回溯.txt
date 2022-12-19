一开始没有记录已经计算过的子串结果超时了。。。
```
func contains(s string, arr []string) bool {
	for _, v := range arr {
		if s == v {
			return true
		}
	}
	return false
}

func wordBreak(s string, wordDict []string) bool {
	m := make(map[int]bool)
	return recursion(s, 0, wordDict, m)
}

func recursion(s string, start int, wordDict []string, m map[int]bool) bool {
	if start == len(s) {
		return true
	}

	for k, v := range m {
		if k == start {
			return v
		}
	}

	for i := start + 1; i <= len(s); {
		subStr := s[start:i]
		if contains(subStr, wordDict) {
			if recursion(s, i, wordDict, m) {
				m[start] = true
				return true
			} else {
				i++
			}
		} else {
			i++
		}
	}
	m[start] = false
	return false
}

```
