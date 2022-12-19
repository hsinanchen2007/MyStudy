1 map 频次统计
```
func countCharacters(words []string, chars string) int {
    letterCountMap := map[rune]int{}
	for _, letter := range chars {
		letterCountMap[letter]++
	}
	ret := 0
	for _, word := range words {
		ok := true
		wordLetterCountMap := map[rune]int{}
		for _, l := range word {
			wordLetterCountMap[l]++
		}
		for k, v := range wordLetterCountMap {
			if v > letterCountMap[k] {
				ok = false
			}
		}
		if ok {
			ret += len(word)
		}
	}
	return ret
}
```

2 库函数 strings.Count
```
func countCharacters(words []string, chars string) int {
	ret := 0
	for _, word := range words {
		ok := true
		for _, v := range word {
			if strings.Count(word, string(v)) > strings.Count(chars, string(v)) {
				ok = false
				break
			}
		}

		if ok {
			ret += len(word)
		}
	}
	return ret
}
```

![image.png](https://pic.leetcode-cn.com/acecae8206b1d1e6d0a745d2ba9878c9f1aa8dc0749b7cf63a37a1417060f338-image.png)

耗时低的是 第二种，strings.Count 的实现。
