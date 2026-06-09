```go
func reverseWords(s string) string {
	parts := strings.Split(s, " ")
	size := len(parts)
	rparts := []string{}
	for i := size - 1; i >= 0; i-- {
		if parts[i] != ""{
			rparts = append(rparts, parts[i])
		}
	}
	return strings.Join(rparts, " ")
}
```