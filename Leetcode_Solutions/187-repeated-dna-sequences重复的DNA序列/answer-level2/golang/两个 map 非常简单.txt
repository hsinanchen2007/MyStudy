```
func findRepeatedDnaSequences(s string) (rst []string) {
	var (
		subMap   = map[string]bool{}
		existMap = map[string]bool{}
	)

	for i := 0; i <= len(s)-10; i++ {
		if subMap[s[i:i+10]] && !existMap[s[i:i+10]] {
			existMap[s[i:i+10]] = true
			rst = append(rst, s[i:i+10])
		} else {
			subMap[s[i:i+10]] = true
		}
	}
	return rst
}
```
