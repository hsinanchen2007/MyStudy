```
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    re := strs[0]
    for _,v := range strs {
        if len(v) < len(re) {
            re = re[0:len(v)]
        }
        for v[0:len(re)] != re {
            if re == "" {
                return ""
            }
            re = re[0:len(re)-1]
        }
    }
    return re
}
```


