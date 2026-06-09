```golang
func reverseWords(s string) string {
    
    // 字符串转换为字节切片
    ss := []byte(s)
    
    // 遍历字节切片，i和j分别指向一个单词的头和尾
    for i, j := 0, 0; j < len(ss); j++ {
        
        if ss[j] == ' ' { // 如果遇到空格，说明单词结束，反转这个单词
            reverseWord(ss, i, j - 1)
            i = j + 1
        } else if j == len(ss) - 1 { // 如果遍历到最后一个元素，也认为当前单词结束，反转这个单词，并退出遍历
            reverseWord(ss, i, j)
            break
        }
    
    }
    
    // 字节切片转回字符串
    return string(ss)
}

func reverseWord(ss []byte, i int, j int) {
    
    if i >= j {
        return
    }
    
    // i和j从两头往中间靠
    for i < j {
        ss[i], ss[j] = ss[j], ss[i]
        i++
        j--
    }

}
```
