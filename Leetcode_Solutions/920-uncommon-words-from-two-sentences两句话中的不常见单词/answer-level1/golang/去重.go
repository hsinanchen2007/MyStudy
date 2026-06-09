```
func uncommonFromSentences(A string, B string) []string {
    c := A + " " +B
    if len(c) == 0 {
        return make([]string, 0)
    }
    arr := strings.Split(c, " ")
    d := map[string]int{}
    for _, v := range arr {
        d[v]++
    }
    result := []string{}
    for key, v := range d {
        if v == 1 {
            result = append(result, key)
        }
    }
    return result
}
```
