```
func findLongestWord(s string, d []string) string {
    // 字典序排序
    sort.Strings(d)
    // 保存长度小于给定字符串的map
    counts := map[int][]*string{}
    maxLen := len(s)
    for i := 0; i < len(d); i++ {
        len := len(d[i])
        if len <= maxLen {
            // 相同长度的字符串按字典顺序添加到count(len)中
            counts[len] = append(counts[len], &d[i])
        }
    }
    // 遍历map 从长度最大的开始遍历 保证先获取的是最长的字符串
    for i := maxLen; i > 0; i-- {
        word := counts[i]
        // 保存满足子序列的字符串
        possibleRes := []string{}
        for j := 0; j < len(word); j++ {
            // 判断是否是子序列
            if containsWord(s, *word[j]) {
                possibleRes = append(possibleRes, *word[j])
            }
        }
        // 取出字典顺序中最小的字符串
        if len(possibleRes) > 0 {
            return possibleRes[0]
        }
    }
    return ""
}

func containsWord(s, v string) bool {
    for len(s) >= len(v) {
        if len(v) == 0 {
            return true
        }
        if s[0] == v[0] {
            v = v[1:]
        }
        s = s[1:]
    }
    return false
}
```
