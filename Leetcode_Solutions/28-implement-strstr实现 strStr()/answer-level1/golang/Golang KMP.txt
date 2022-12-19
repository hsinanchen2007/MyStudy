### 解题思路
此处撰写解题思路

### 代码

```golang
func strStr(haystack string, needle string) int {
    if len(needle) == 0 {
        return 0
    }
    if len(haystack) == 0 {
        return -1
    }
    if len(haystack) < len(needle) {
        return -1
    }
    var (
        i = 0
        j = 0
        part = getPartMatch(needle)
    )
    for i < len(haystack) && j < len(needle) {
        if haystack[i] == needle[j] {
            i ++
            j ++
        }else {
            if j == 0 {
                i ++
                j = 0
            }else {
                i = i - part[j-1]
                j = 0
            }
        }
    }
    if j >= len(needle) {
        return i-j
    }
    return -1
}

func getPartMatch(s string) []int {
    var (
        result = make([]int,len(s))
        i = 0
        j = 1
    )
    for j < len(s) {
        if s[i] == s[j] {
            result[j] = i+1
            i ++
            j ++
        }else {
            if i == 0 {
                j ++
            }else {
                i = result[i-1]
            }
        }
    }
    return result
}
```