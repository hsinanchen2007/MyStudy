### 解题思路
遍历字符串，用两个变量begin,end记录当前没有重复字符的子串开头和结尾位置。
已出现的字符用一个map记录最新的位置，遍历时每次移动end位置时从map中读取进行判重。
如果有重复，记录当前无重复的子串长度，根据重复字符位置信息，修改begin。
### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    var maxLen, begin, end int
    exist := make(map[rune]int)

    for end = 0; end < len(s); end++ {
        c := rune(s[end])
        if location, ok := exist[c]; ok {
            crrLen := end - begin
            if crrLen > maxLen {
                maxLen = crrLen
            }
            if location >= begin {
                begin = location + 1
            }
        }
        exist[c] = end
    }
    lastLength := end - begin
    if lastLength > maxLen {
        maxLen = lastLength
    }
    return maxLen
}
```