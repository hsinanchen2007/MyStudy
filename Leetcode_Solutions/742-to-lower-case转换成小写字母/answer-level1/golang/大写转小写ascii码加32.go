```
func toLowerCase(str string) string {
    if len(str) == 0 {
        return str
    }

    runes := []rune(str)
    for i:=0;i<len(runes);i++ {
        if runes[i] >= 65 && runes[i] <= 90 {
            runes[i] = runes[i] + 32
        }
    }

    return string(runes)
}
```
