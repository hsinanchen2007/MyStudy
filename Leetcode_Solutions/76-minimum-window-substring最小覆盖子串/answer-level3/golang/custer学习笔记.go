
# 思考

同样是两个字符串之间的关系问题，因为题目要求的最小子串，也就是窗口的最小长度，说明这里的窗口大小是可变的，这里移动左指针的条件变成，只要左指针指向不需要的字符，就进行移动

```go
func minWindow(s string, t string) string {
	if len(s) < len(t) {
		return ""
	}
	hash := make([]int, 256)
	for i := 0; i < len(t); i++ {
		hash[t[i]]++
	}
	l, count, max, results := 0, len(t), len(s)+1, ""
	for r := 0; r < len(s); r++ {
		hash[s[r]]--
		if hash[s[r]] >= 0 {
			count--
		}
		for l < r && hash[s[l]] < 0 {
			hash[s[l]]++
			l++
		}
		if count == 0 && max > r-l+1 {
			max = r - l + 1
			results = s[l : r+1]
		}
	}

	return results
}
```