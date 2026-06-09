兼容Unicode字符，滑动窗口

```go
func lengthOfLongestSubstring(s string) int {
    var start, max int
    q := make(map[rune]int)

    for i, v := range s {
        if index, ok := q[v]; ok && index >= start {
            start = index + 1
        }
        q[v] = i

        if i - start + 1 > max {
            max = i - start + 1
        } 
    }
    return max
}
```
