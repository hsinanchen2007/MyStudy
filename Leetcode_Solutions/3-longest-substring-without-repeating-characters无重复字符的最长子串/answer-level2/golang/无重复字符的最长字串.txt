```golang
func lengthOfLongestSubstring(s string) int {
    
    // 最大长度
    maxLen := 0
    // 记录每个字符的索引位置
    foundChars := make(map[byte]int)
    // 初始化两个索引，i是子串的开始索引，j是遍历索引
    i, j := 0, 0

    for ; j < len(s); j++ {

        // 当前字符
        currChar := s[j]

        // 如果当前字符已经存在，则取出之前的索引
        if lastIndex, ok := foundChars[currChar]; ok {
            // 计算最大长度
            if j - i > maxLen {
                maxLen = j - i
            }
            // 如果子串的起始位置已经越过了当前字符的上个位置，则继续使用当前的子串起始位置，否则就更新它
            if lastIndex + 1 > i {
                i = lastIndex + 1
            }
        }
        // 记录每个字符的索引
        foundChars[currChar] = j
    }
    
    // 由于上面计算最大长度，只在遇到相同字符时才遇到，这里处理没有遇到相同字符的情况
    if j - i > maxLen {
        maxLen = j - i
    }
    
    return maxLen
}
```
