```
func countLetters(S string) int {
	var (
		result int
		p int = 1
	)
	for i := 0; i < len(S)-1;i ++{
		if S[i] == S[i+1]{
			p++
		}else {
			result += (1+p)*p/2
			p = 1
		}
	}
	result += (1+p)*p/2
	return  result
}
```
