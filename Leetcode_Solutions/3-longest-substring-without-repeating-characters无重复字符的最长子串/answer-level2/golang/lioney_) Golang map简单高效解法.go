```
func lengthOfLongestSubstring(s string) int {
    var strMap = make(map[byte]int)
    left, res := 0, 0
    for i := 0; i < len(s); i++ {
        if v, ok := strMap[s[i]]; ok {
            left = max(left, v + 1)  
        }
        strMap[s[i]] = i
        res = max(res, i-left+1)
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```
