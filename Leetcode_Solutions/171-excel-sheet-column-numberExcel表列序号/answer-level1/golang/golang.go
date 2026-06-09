```
func titleToNumber(s string) int {
    result := 0

	for i, c := range s {
		result += int(c-64) * int(math.Pow(float64(26), float64(len(s)-1-i)))
	}

	return result
}
```