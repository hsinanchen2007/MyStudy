```
func uncommonFromSentences(A string, B string) []string {

	list := strings.Split(A + " " + B, " ")
	m := map[string]int{}

	for _, v := range list {
		m[v] ++
	}


	list = []string{}
	for k, _ := range m {
		if m[k] == 1 {
			list = append(list, k)
		}
	}

	return list
}
```
