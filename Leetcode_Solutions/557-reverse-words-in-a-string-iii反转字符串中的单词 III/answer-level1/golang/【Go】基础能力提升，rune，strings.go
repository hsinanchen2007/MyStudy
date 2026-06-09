```
func reverseWord(s string) string {
	r := []rune(s)
	for i, j := 0, len(r) - 1; i < len(r) / 2; i, j = i + 1, j - 1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func reverseWords(s string) string {
	words := strings.Split(s," ")
	for i, v := range words {
		words[i] = reverseWord(v)
	}
	return strings.Join(words, " ")
}
```
