```go
func minCut(s string) int {
    // state: f[i] "前i"个字符组成的子字符串需要最少几次cut(个数-1为索引)
    // function: f[i] = MIN{f[j]+1}, j < i && [j+1 ~ i]这一段是一个回文串
    // intialize: f[i] = i - 1 (f[0] = -1)
    // answer: f[s.length()]
	if len(s) == 0 || len(s) == 1 {
		return 0
	}
	f := make([]int, len(s)+1)
	f[0] = -1 // 初始化时为f[i]=i-1
	f[1] = 0
	for i := 1; i <= len(s); i++ {
		f[i] = i - 1
		for j := 0; j < i; j++ {
			if isPalindrome(s, j, i-1) {
				f[i] = min(f[i], f[j]+1)
			}
		}
	}
	return f[len(s)]
}
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
func isPalindrome(s string, i, j int) bool {
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}

```
