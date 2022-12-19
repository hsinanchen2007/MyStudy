```go
func uniqueMorseRepresentations(words []string) int {
	codes := []string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}

	buffer := bytes.Buffer{}
	uniqueWord := make(map[string]bool)
	for _, word := range words {
		buffer.Reset()
		for _, letter := range word {
			buffer.WriteString(codes[letter-'a'])
		}
		uniqueWord[buffer.String()] = true
	}
	return len(uniqueWord)
}
```

简化实现学习 https://leetcode-cn.com/problems/unique-morse-code-words/solution/4msgo-shi-xian-by-elliotxx-4/

```go
func uniqueMorseRepresentations2(words []string) int {
	table := []string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}
	hash := map[string]bool{}
	for _, w := range words {
		t := ""
		for _, x := range w {
			t += table[x-'a']
		}
		hash[t] = true
	}
	return len(hash)
}
```