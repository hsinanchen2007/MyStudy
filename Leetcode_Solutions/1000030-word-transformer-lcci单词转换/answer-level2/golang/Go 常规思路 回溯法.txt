```go
func findLadders(beginWord string, endWord string, wordList []string) []string {
    memo := make(map[string]bool)
    return dfs(beginWord, endWord, 0, []string{beginWord}, wordList, memo)
}


func dfs(beginWord string, endWord string, index int, tmp, wordList []string, memo map[string]bool) []string{
    if _, ok := memo[beginWord]; ok {
        return nil
    }
    if beginWord == endWord {
        return tmp
    }

    if index >= len(wordList) {
        return nil
    }

    for i := index; i < len(wordList); i++ {
        if !onlyOneDifference(beginWord, wordList[i]) {
            continue
        }
        t := wordList[i]
        wordList[i], wordList[index] = wordList[index], wordList[i]
        newTmp := make([]string, len(tmp))
        copy(newTmp, tmp)
        newTmp = append(newTmp, t)
        result:=dfs(t, endWord, index+1, newTmp, wordList, memo)
        if result != nil {
            return result
        }
        wordList[i], wordList[index] = wordList[index], wordList[i]
        memo[t] = true

    }

    return nil

}


func onlyOneDifference(s1, s2 string) bool {
    different := 0
    for i := 0; i < len(s1); i++ {
        if s1[i] != s2[i] {
            different ++
        }
    }

    if different == 1 {
        return true
    }
    return false
}
```