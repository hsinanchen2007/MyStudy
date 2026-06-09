```
func toLowerCase(str string) string {
    var buf bytes.Buffer
	for _, c := range str {
		if c >= 65 && c <= 90 {
			buf.WriteRune(c + rune(32))
		} else {
			buf.WriteRune(c)
		}
	}
	return buf.String()
}
```