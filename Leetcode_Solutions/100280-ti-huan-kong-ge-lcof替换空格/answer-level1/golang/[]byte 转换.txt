```
func replaceSpace(s string) string {
	var (
		i, total int
		length   = len(s)
		bytes    = make([]byte, length*3)
	)

	for i = 0; i < length; i++ {
		if s[i] == ' ' {
			bytes[total] = '%'
			bytes[total+1] = '2'
			bytes[total+2] = '0'
			total += 3
		} else {
			bytes[total] = s[i]
			total++
		}
	}
	return string(bytes[:total])
}
```
