### 解题思路
Go 直接写了

### 代码

```golang

func replaceWords(dict []string, sentence string) string {
	sort.Slice(dict, func(i, j int) bool {
		return len(dict[i]) < len(dict[j])
	})

	words := strings.Split(sentence, " ")
	for i := 0; i < len(words); i++ {
		for j := 0; j < len(dict); j++ {
			if strings.HasPrefix(words[i], dict[j]) {
				words[i] = dict[j]
				break
			}
		}
	}

	return strings.Join(words, " ")
}

```