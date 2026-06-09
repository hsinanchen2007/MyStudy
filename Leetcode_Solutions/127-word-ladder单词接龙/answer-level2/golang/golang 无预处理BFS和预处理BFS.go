
1. 没有预处理的BFS，用时288ms
```
func ladderLength(beginWord string, endWord string, wordList []string) int {
    // 排除wordList中没有endWord，直接返回0
	flag := false
	for _, word := range wordList {
		if word == endWord {
			flag = true
			break
		}
	}
	if !flag {
		return 0
	}
	// 1. bfs 效率不佳，288ms
	wordMap := make(map[string]bool)  // 是否访问过了
	queue := []string{beginWord}      // init queue
	count := 0                        // count
	for len(queue) > 0 {
		count++                       // 每次访问一层+1
		newQueue := make([]string, 0) // 下一层数据
		for _, item := range queue {
			for _, word := range wordList {
				diff := 0
				for i := 0; i < len(item); i++ {
					if item[i] != word[i] {
						diff++
					}
				}
				if diff == 1 && !wordMap[word] {
					if word == endWord {
						return count + 1
					}
					wordMap[word] = true
					newQueue = append(newQueue, word)
				}
			}
		}
		queue = newQueue              // 将新的数据替换，继续循环
	}
	return 0
```


2. 预处理+BFS，用时40ms

预处理就是将wordList中的所有单词，每个单词的每个字母换成"*"，换完之后一样的放在一个list中
后续每次对比diff==1，就只需要对比对应list中的单词即可，不需要全部过一遍了
```
func ladderLength(beginWord string, endWord string, wordList []string) int {
	flag := false
	for _, word := range wordList {
		if word == endWord {
			flag = true
			break
		}
	}
	if !flag {
		return 0
	}
	// 2. 预处理+bfs, 40ms
	visitedMap := make(map[string]bool)
	preMap := make(map[string][]string)          // 预处理结果map
	queue := []string{beginWord}
	count := 0
	worldLen := len(beginWord)
	for _, word := range wordList {              // 预处理
		for i := 0; i < worldLen; i++ {
			key := word[:i] + "*" + word[i+1:]
			preMap[key] = append(preMap[key], word)
		}
	}
	for len(queue) > 0 {
		count++
		newQueue := make([]string, 0)
		for _, item := range queue {
			for i := 0; i < worldLen; i++ {
				key := item[:i] + "*" + item[i+1:]
				for _, word := range preMap[key] {
					if word == endWord {
						return count + 1
					}
					if !visitedMap[word] {
						visitedMap[word] = true
						newQueue = append(newQueue, word)
					}
				}
			}
		}
		queue = newQueue
	}
	return 0
}
```
