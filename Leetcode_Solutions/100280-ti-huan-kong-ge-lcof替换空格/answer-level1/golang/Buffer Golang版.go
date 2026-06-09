```
func replaceSpace(s string) string {
    var buf bytes.Buffer
    for _, v := range s {
        if v == ' ' {
            buf.WriteString("%20")
            continue
        }
        buf.WriteRune(v)
    }
    return buf.String()
}
```