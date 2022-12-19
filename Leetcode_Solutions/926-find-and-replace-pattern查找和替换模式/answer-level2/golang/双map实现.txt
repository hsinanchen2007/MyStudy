思路就是官方方法一中的，一个字典保证一个字母不会映射到俩字母，第二个字典保证不会有两个字母映射到同一个字母。
```

func findAndReplacePattern(words []string, pattern string) []string {
	var ret = make([]string, 0)
	var index = 0
	for _, word := range words {
		var i = 0
		var pattern_maps = make(map[rune]rune)
		var fun_maps = make(map[rune]rune)
		for _, value := range word {
			if _, ok := pattern_maps[value]; !ok {
				if _, ok := fun_maps[rune((pattern[i]))]; !ok {
					pattern_maps[value] = rune(pattern[i])
					fun_maps[rune(pattern[i])] = value
				} else {
					if fun_maps[rune(pattern[i])] != value {
						break
					}
				}
				i++
			} else {
				if pattern_maps[value] == rune((pattern[i])) && fun_maps[rune((pattern[i]))] == value {
					i++
				} else {
					break
				}
			}
		}
		if i == len(word) {
			ret = append(ret, word)
			index++
		}
	}

	return ret
}
```
