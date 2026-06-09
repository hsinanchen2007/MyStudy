```

import "strings"

func reverseWords(s string) string {
	var (
		i, j   int
		tmp    string
		ss     = strings.Split(s, " ")
		length = len(ss)
	)

	j = 0
	for i = 0; i < length; i++ {
		tmp = strings.TrimSpace(ss[i])
		if len(tmp) != 0 {
			ss[j] = tmp
			j++
		}
	}
	for i = 0; i < j/2; i++ {
		ss[i], ss[j-1-i] = ss[j-1-i], ss[i]
	}

	return strings.Join(ss[:j], " ")
}

```
