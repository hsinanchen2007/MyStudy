不知道为什么第一次跑了0ms，一般4ms到12ms不等
思路是把所有可能的子串都扫一遍，最多扫单词长度个子串，每个子串在扫的时候用ac自动机的想法，能达到o(n)的时间复杂度

```
func findSubstring(s string, words []string) []int {
    w2num := make(map[string]uint8)
    allNum := len(words)
    if allNum == 0 {
        return []int{}
    }
    length :=  len(words[0])
    if length == 0 {
        return []int{}
    }
    for _, str := range(words) {
        w2num[str] += 1
    }
    tmp := (make([]int, 0, 30))
    re := &tmp
    for i:=0; i<len(s)-allNum*length+1 && i<length; i++ {
        isSub(s[i:], w2num, length, allNum, re, 0, 0, i) 
    }
    return *re
}

func isSub(s string, w2num map[string]uint8, length int, allNum int, re *[]int, start int, end int, offset int) {
    if len(s[end:]) - allNum*length < 0 {
        return
    }
    tmp, ok := w2num[s[end:end+length]]
    if ok && tmp>0 {
        //能进下一状态
        w2num[s[end:end+length]] -= 1
        allNum -= 1
        end += length
        if allNum == 0 {
            *re = append(*re, start+offset)
            w2num[s[start:start+length]] += 1
            allNum += 1
            start += length
            isSub(s, w2num, length, allNum, re, start, end, offset)
            start -= length
            allNum -= 1
            w2num[s[start:start+length]] -= 1
        } else {
            isSub(s, w2num, length, allNum, re, start, end, offset)
        }
        end -= length
        allNum += 1
        w2num[s[end:end+length]] += 1
    } else {
        if end > start {
            w2num[s[start:start+length]] += 1
            allNum += 1
            start += length
            isSub(s, w2num, length, allNum, re, start, end, offset)
            start -= length
            allNum -= 1
            w2num[s[start:start+length]] -= 1
        } else {
            isSub(s, w2num, length, allNum, re, start+length, end+length, offset)
        }
    }
}
```

