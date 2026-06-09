```
func lengthOfLastWord(s string) int {
    
    if len(s) == 0 {
        return 0
    }
    
    // 最后一个单词的长度
    lastWordLen := 0

    // 是否遇到了最后一个单词
    lastWordBegin := false
    
    // 从字符串尾部往前遍历
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] != ' ' { // 遇到非空格字符，则开始累加最后一个单词的长度
            lastWordBegin = true
            lastWordLen++
        } else if lastWordBegin { // 如果已经找到了最后一个单词，且又遇到了空格字符，则最后一个单词结束了
            break
        }
        // 过滤尾部空格字符
    }
    
    return lastWordLen
}
```
