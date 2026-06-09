```go
func maxNumberOfBalloons(text string) int {
	charCount := [26]int{}
	charArray := []rune(text)
	for _, v := range charArray {
		charCount[v - 'a']++
	}
	charCount['l' - 'a'] /= 2
	charCount['o' - 'a'] /= 2
	min := len(charArray)
	for _, v := range []rune("balloon") {
		if charCount[v - 'a'] < min {
			min = charCount[v - 'a']
		}
	}
	return min
}
```