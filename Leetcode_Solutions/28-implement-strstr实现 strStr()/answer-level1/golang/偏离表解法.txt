思路：
- 将待匹配字符串视为整体，将目标字符串从 0 到 n-m 遍历，其中 n 为目标字符串的长度，m 为待匹配字符串的长度。
- 每次对比目标字符串的一部分 str[i:i+m] 与 待匹配字符串 subStr,一直到等式成立

代码：

```go
func strStr(haystack string, needle string) int {
    m := len(needle)
    n := len(haystack)
    
    if m == 0 {
        return 0
    }
    
    if m == n {
        if haystack == needle {
            return 0
        }
        
        return -1
    }
    
    
    for i := 0; i <= n-m; i++ {
        if haystack[i:i+m] == needle {
            return i
        }
    }
    
    return -1
}
```

> 时间复杂度击败 100% 用户