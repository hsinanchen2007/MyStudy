```go
func countAndSay(n int) string {
	return say(n, "1")
}

func say(target int, read string) string {
	if target == 1 {
		return read
	}

	return say(target-1, sayString(read))
}

func sayString(str string) string {
	res := strings.Builder{}

	var last rune
	amt := 0

	for _, v := range str {
		if amt > 0 {
			if last == v {
				amt++
			} else {
				res.WriteString(strconv.Itoa(amt))
				res.WriteRune(last)
				amt = 1
				last = v
			}
		} else {
			last = v
			amt++
		}
	}

	res.WriteString(strconv.Itoa(amt))
	res.WriteRune(last)

	return res.String()
}
```