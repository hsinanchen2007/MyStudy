### 解题思路
Go,Go,Go

### 代码
### 普通BFS，超时，呜呜
```golang
func ladderLength1(beginWord string, endWord string, wordList []string) int {
    queue := []string{beginWord}
    var step int 
    visited := make(map[string]bool)
    for len(queue)!=0 {
        size := len(queue)
        step++
        for size >0 {
            tmpstr := queue[0]
            queue = queue[1:]
            for i:=0;i<len(wordList);i++{
                if _,ok := visited[wordList[i]];!ok {
                    if compare(tmpstr,wordList[i]) {
                        if endWord == wordList[i] {
                            return step+1
                        }
                        queue = append(queue,wordList[i])
                        visited[wordList[i]] = true
                    }
                    
                }
            }
            size--
        }
    }
    return 0
}
```
### 双端BFS，也不过如此，嘻嘻
```golang
func ladderLength(beginWord string, endWord string, wordList []string) int {
    //判断边界
    var flag bool
    for i:=0;i<len(wordList);i++{
        if wordList[i] == endWord {
            flag = true
            break
        }
    }
    if !flag {return 0}

    var res int
    lqueue,rqueue := []string{beginWord},[]string{endWord}
    visited := make(map[string]bool)
    for len(lqueue)!=0 {
        res++
        tmpqueue := []string{}
        size := len(lqueue)

        for size>0 {
            str := lqueue[0]
            lqueue = lqueue[1:]
            //判断在另个对列是否已经存在，如果存在，则返回
            for i:=0;i<len(rqueue);i++{
                if compare(str,rqueue[i]) {
                    return res+1
                }
            }
            //如果不存在，则从未访问过的单词中选择加入队列中
            for i:=0;i<len(wordList);i++{
                if _,ok:=visited[wordList[i]];!ok&&compare(str,wordList[i]) {
                    tmpqueue = append(tmpqueue,wordList[i])
                    visited[wordList[i]] = true
                }
            }
            size--
        }
        lqueue = tmpqueue
        if len(lqueue)>=len(rqueue) {
            lqueue,rqueue = rqueue,lqueue
        }
        fmt.Println(lqueue,rqueue)
    }
    fmt.Println(lqueue)

    return 0
}

func compare(str1,str2 string) bool{
    var count int
    for i:=0;i<len(str1);i++{
        if str1[i]!=str2[i] {
            count++
        }
    }
    return count==1
}

```