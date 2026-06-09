```
func lengthOfLastWord(s string) int {
	strSlice := strings.Fields(s)
	if len(strSlice) == 0 {
		return 0
	}
	return len(strSlice[len(strSlice)-1])
}

```