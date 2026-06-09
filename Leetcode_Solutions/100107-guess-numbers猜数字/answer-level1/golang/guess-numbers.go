```
func game(guess []int, answer []int) int {
	var count int
	for i, v := range guess {
		if v == answer[i] {
			count++
		}
	}
	return count
}
```
