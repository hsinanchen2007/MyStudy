```
func longestPalindrome(s string) string {
	runes := []rune(s)
	lenth := len(runes)
	if lenth == 0 {
		return ""
	}
	if lenth == 1 {
		return string(runes)
	}

	longest, start := -1, 0
	dp := make([]map[int]int, lenth)
	for i := 0; i < len(runes); i++ {
		if len(dp[i]) == 0 {
			dp[i] = make(map[int]int)
		}

		dp[i][i] = 1
		if i < len(runes)-1 {
			if runes[i] == runes[i+1] {
				dp[i][i+1] = 1
				start = i
				longest = 2
			}
		}
	}

	for l := 3; l <= len(runes); l++ {

		for i := 0; i+l-1 < len(runes); i++ {
			j := i + l - 1
			if runes[i] == runes[j] && dp[i+1][j-1] == 1 {
				dp[i][j] = 1
				start = i
				longest = l
			}
		}
	}
	if longest == -1 {
		return string(runes[start : start+1])
	}
	return string(runes[start : longest+start])
}
```
