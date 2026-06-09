```
func findWords(words []string) []string {
    m := map[string]int{"q": 0, "w": 0, "e": 0, "r": 0, "t": 0, "y": 0, "u": 0, "i": 0, "o": 0, "p": 0,
		"a": 1, "s": 1, "d": 1, "f": 1, "g": 1, "h": 1, "j": 1, "k": 1, "l": 1,
		"z": 2, "x": 2, "c": 2, "v": 2, "b": 2, "n": 2, "m": 2}

	result := []string{}

	for _, word := range words {
		if len(word) == 0 {
			continue
		}

		key := -1
		for i, c := range word {
			if i == 0 {
				if v, ok := m[string(c)]; ok {
					key = v
					continue
				}

				if v, ok := m[string(c+32)]; ok {
					key = v
					continue
				}
			} else {
				if v, ok := m[string(c)]; ok {
					if key == v {
						continue
					} else {
						key = -1
						break
					}
				}

				if v, ok := m[string(c+32)]; ok {
					if key == v {
						continue
					} else {
						key = -1
						break
					}
				}
			}
		}

		if key != -1 {
			result = append(result, word)
		}
	}

	return result
}
```