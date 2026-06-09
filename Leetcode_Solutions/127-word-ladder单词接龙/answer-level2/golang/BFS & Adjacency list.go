邻接表
```
func ladderLength(beginWord string, endWord string, wordList []string) int {
    adjList := make(map[string][]string)
    wordList = append(wordList, beginWord)
    for _, v := range wordList {
        adjList[v] = []string{}
    }
    res := 0
    if _, ok := adjList[endWord]; !ok {
        return res
    }
    //Adjacency list
    for word, _ := range adjList {
        for j:=0; j < len(word); j++{
            for c := 'a'; c <= 'z'; c++ {
                newword := word[:j]+string(c)+word[j+1:]
                if newword == word {
                    continue
                }
                if _,ok := adjList[newword]; ok {
                    adjList[word] = append(adjList[word], newword)
                }
            }
        }
    }
    //fmt.Println(adjList)
    //bfs
    queue := []string{}
    queue = append(queue, beginWord)
    for len(queue) > 0 {
        qlen := len(queue)
        for i:=0; i < qlen; i++ {
            word := queue[0]
            //pop
            queue = queue[1:len(queue)]
            if word == endWord {
                return res+1
            }
            if list, ok := adjList[word]; ok {
                for _, newword := range list {
                    queue = append(queue, newword)
                }
                delete(adjList, word)
            }
        }
        res++        
    }

    return 0
}
```


直接BFS搜索
```
func ladderLength(beginWord string, endWord string, wordList []string) int {
    set := make(map[string][]string)
    for _, v := range wordList {
        set[v] = []string{}
    }
    res := 0
    if _, ok := set[endWord]; !ok {
        return res
    }
    //bfs
    queue := []string{}
    queue = append(queue, beginWord)
    for len(queue) > 0 {
        qlen := len(queue)
        for i := 0; i < qlen; i++ {
            word := queue[0]
            fmt.Println(word)
            //pop()
            queue = queue[1: len(queue)]
            if word == endWord {
                return res + 1
            }
            for j:=0; j < len(word); j++{
                for c := 'a'; c <= 'z'; c++ {
                    newword := word[:j]+string(c)+word[j+1:]
                    if newword == word {
                        continue
                    }
                    if _,ok := set[newword]; ok {
                        queue = append(queue, newword)
                        //
                        delete(set, newword)
                    }
                }
            }
        }
        res++
    }
    return 0
}
```
