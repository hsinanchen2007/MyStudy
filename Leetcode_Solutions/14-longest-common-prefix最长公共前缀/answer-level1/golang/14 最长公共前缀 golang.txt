思路分析：

最长公共前缀一定存在最短的那个字符串中，因此先求出最短的字符串的长度minLen，然后依次比较每个字符串中的第i个字符(0 <= i < minLen)，如果相同则追加到结果中，否则退出，返回之前的结果。

算法实现：

```go
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {return ""}
    if len(strs) == 1 {return strs[0]}
    // 找出最短字符串的长度
    minLen := 1 << 31 -1
    for _, str := range strs {
        if len(str) < minLen {
            minLen = len(str)
        }
    }
    var res string
    // 比较每个字符串的第i位
    for i:= 0; i < minLen; i++ {
        r := strs[0][i]
        ok := true
        for j := 1; j < len(strs); j++ {
            if r != strs[j][i] {
                ok = false
                break
            }
        }
        if !ok {
            break
        }
        res = res + string(r)
    }
    return res
}
```

