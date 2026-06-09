```
func gcdOfStrings(str1 string, str2 string) string {
    if str1 == str2 {
        return str1
    }

    s1Len := len(str1)
    s2Len := len(str2)
    
    if s1Len == 0 {
        return str2
    }
    if s2Len == 0 {
        return str1
    }

    // 保证s1长度永远大于s2
    if s1Len < s2Len {
        str1, str2 = str2, str1
        s1Len, s2Len = s2Len, s1Len
    }
    if strings.HasPrefix(str1, str2) {
        return gcdOfStrings(string(str1[s2Len:]), str2)
    }

    return ""
}
```
