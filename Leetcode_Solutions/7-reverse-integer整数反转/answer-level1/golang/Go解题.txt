```go
func reverse(x int) int {
	t := 1
	if x < 0 {
		t = -1
		x = t * x
	}
	s := strconv.Itoa(x)
	runes := []rune(s)
	l := len(runes)
	for f, to := 0,  l - 1; f < to; f, to = f + 1, to -1 {
		runes[f], runes[to] = runes[to], runes[f]
	}
	MaxInt32  := 1<<31 - 1
	MinInt32  := -1 << 31
	x, _ = strconv.Atoi(string(runes))
	x = x * t
    fmt.Println(int32(x))
	if x > MaxInt32 || x < MinInt32 {
		return 0
	} else {
		return x
	}
}
```
