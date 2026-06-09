1.整理字典
2.DFS
3.记录路径
4.在push的时候使用result = append(result, nextWord) 
4.在pop的时候使用result = result[0 : len(result) - 1]
```
func findLadders(beginWord string, endWord string, wordList []string) []string {

	words := make([]string, 0)
	words = append(wordList, beginWord)

	wordDictionary := make(map[string][]string, 0)
	buildWordDictionary(words, wordDictionary)

	wordVisited := make(map[string]bool)
	for k := range wordDictionary {
		wordVisited[k] = false
	}

	result := make([]string, 0)
	var dfs func(current string) bool
	dfs = func(current string) bool {
		if current == endWord {
			return true
		}

		nextWords := wordDictionary[current]
		for _, nextWord := range nextWords {
			if visited, ok := wordVisited[nextWord]; ok && visited {
				continue
			}
			wordVisited[nextWord] = true
			result = append(result, nextWord)
			if !dfs(nextWord) {
				result = result[0 : len(result) - 1]
				continue
			} else {
				return true
			}
		}
		return false
	}

	wordVisited[beginWord] = true
	result = append(result, beginWord)
	if dfs(beginWord) {
		return result
	}
	return nil
}

func buildWordDictionary(wordList []string, wordDictionary map[string][]string) {
	wordCount := len(wordList)
	for i := 0; i < wordCount; i++ {
		for j := i + 1; j < wordCount; j++ {
			from := wordList[i]
			to := wordList[j]
			if len(from) != len(to) {
				continue
			}
			diffCount := 0
			for i, c := range from {
				if uint8(c) == to[i] {
					continue
				}
				diffCount++
				if diffCount > 1 {
					break
				}
			}

			if diffCount == 1 {
				if _, ok := wordDictionary[from]; ok {
					wordDictionary[from] = append(wordDictionary[from], to)
				} else {
					wordDictionary[from] = append(make([]string, 0), to)
				}

				if _, ok := wordDictionary[to]; ok {
					wordDictionary[to] = append(wordDictionary[to], from)
				} else {
					wordDictionary[to] = append(make([]string, 0), from)
				}
			}
		}
	}
}
```
