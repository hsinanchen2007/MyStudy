```go
func findLadders(beginWord string, endWord string, wordList []string) []string {
    path := map[string][]string{beginWord: []string{beginWord}, endWord: []string{endWord}}
    startQueue :=  map[string]bool{beginWord: true}
    endQueue := map[string]bool{endWord: true}
    wordDict := make(map[string]bool)
    for _, word := range wordList {
        wordDict[word] = true
    }
    if !wordDict[endWord] {
        return nil
    }
    // 用来记录是否为正向遍历，因为反向遍历时记录新路径的方向与正向遍历相反
    isBackward := false

    for len(startQueue) > 0 && len(endQueue) > 0 {
        if len(startQueue) > len(endQueue) {
            startQueue, endQueue = endQueue, startQueue
            isBackward = !isBackward
        }
        tempQueue := make(map[string]bool)
        for word := range startQueue {
            chars := []byte(word)
            for i := 0; i < len(chars); i++ {
                old := chars[i]
                for j := byte('a'); j <= 'z'; j++ {
                    chars[i] = j
                    newWord := string(chars)
                    if endQueue[newWord] {
                        startLen, endLen := len(path[word]), len(path[newWord])
                        res := make([]string, startLen + endLen)
                        if isBackward {
                            copy(res, path[newWord])
                            copy(res[endLen:], path[word])
                        } else {
                            copy(res, path[word])
                            copy(res[startLen:], path[newWord])                            
                        }
                        return res
                    }
                    if j != old && wordDict[newWord] && len(path[newWord]) == 0 {
                        path[newWord] = make([]string, len(path[word])+1)
                        if isBackward {
                            path[newWord][0] = newWord
                            copy(path[newWord][1:], path[word])
                        } else {
                            copy(path[newWord], path[word])
                            path[newWord][len(path[newWord])-1] = newWord                            
                        }
                        tempQueue[newWord] = true
                    }
                }
                chars[i] = old
            }
        }
        startQueue = tempQueue
    }

    return nil
}
```