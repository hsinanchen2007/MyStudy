```
func lengthOfLastWord(s string) int {
	stra := strings.Trim(s," ")
	strs := strings.Split(stra," ")
	return len(strs[len(strs)-1:][0])
}

```
