### 解题思路


### 代码

```golang
func compressString(S string) string {
    if len(S) == 0 {
        return ""
    }
    var (
        pos = 1
        count = 1
        cur = S[0]
        str = strings.Builder{}
    )
    for pos < len(S) {
        if cur == S[pos] {
            count ++
            pos ++
        }else {
            str.WriteString(string(cur)+strconv.Itoa(count))
            count = 1
            cur = S[pos]
            pos ++
        }
    }
    str.WriteString(string(cur)+strconv.Itoa(count))
    if str.Len() >= len(S) {
        return S
    }
    return str.String()
}
```