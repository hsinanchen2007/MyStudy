`string` 先行转化为 `[]byte`, 然后对数组原地再转化为 string.

```go []
func reverseWords(s string) string {
	b := []byte(s)

	var i, j int

	for j < len(b) {
		if b[j] == ' ' {
			if j > i {
				reverse(b, i, j-1)
			}

			j++
			i = j
		} else {
			j++
		}
	}

	if j > i {
		reverse(b, i, j-1)
	}

	return string(b)
}

func reverse(b []byte, i, j int) {
	for i < j {
		b[i], b[j] = b[j], b[i]
		i++
		j--
	}
}
```
