```
func strStr(haystack string, needle string) int {
    
    if len(needle) == 0 {  // 按照题目要求返回0
        return 0
    } else if len(needle) > len(haystack) {  // haystack比needle短，那肯定找不到needle
        return -1
    }
    
    // 开始匹配的索引
    startPos := 0
    // 当前匹配字符的索引
    needlePos := 0
    // 是否找到needle
    found := false
    
    for {
        // needle或者haystack结束了，则退出循环
        if needlePos > len(needle) - 1 || startPos + needlePos > len(haystack) - 1 {
            break
        }
        
        // 如果当前字符匹配，则移动needlePos索引，继续下一个字符的匹配，如果已经到needle末尾了，则成功返回
        if needle[needlePos] == haystack[startPos + needlePos] {
            if needlePos == len(needle) - 1 {
                found = true
                break
            }
            needlePos++
        } else { // 如果当前字符匹配失败，则移动开始索引，并重置当前匹配字符的索引
            startPos++
            needlePos = 0
        }
    }
    
    if found {
        return startPos
    }
    
    return -1
    
}
```
