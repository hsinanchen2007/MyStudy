
```
func lengthOfLongestSubstring(s string) int {
    if s == "" {
        return 0
    }
    b := []byte(s)
    n := 0
    maxLen := 0
    var subStr []byte
    for i:=0; i<len(b); i++ {
        index := bytes.IndexByte(subStr, b[i])
        if index >= 0 {
            n += index + 1
        }
        subStr = b[n:i+1]
        if len(subStr) > maxLen {
            maxLen = len(subStr)
        }
    }
    return maxLen
}
```
