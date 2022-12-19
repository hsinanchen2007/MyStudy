这种目标字符串在集合中得题。通过大 -> 小 往往更加容易
```go

import "sort"

type sortWords []string

func(s sortWords) Len() int {
    return len(s)
}

func(s sortWords) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func(s sortWords) Less(i, j int) bool {
    return len(s[i]) >= len(s[j])
}

func longestWord(words []string) string {
    longest := 0
    wordsMap := make(map[string]bool)

    for _, word := range words {
        wordsMap[word] = true
        if longest < len(word) {
            longest = len(word)
        }
    }
    sort.Sort(sortWords(words))
    fmt.Println(words)
    for _, word := range words {
        delete(wordsMap, word)
        if dfs(word, wordsMap) {
            return word 
        }
    }
    return "" 
}

func dfs(word string, wordsMap map[string]bool) bool {
    if word == "" {
        return true
    }
    for i := 1; i <= len(word); i++ {
        if _, ok := wordsMap[word[:i]];ok {
            if dfs(word[i:], wordsMap) {
                return true
            }
        }
    }
    return false
}
```