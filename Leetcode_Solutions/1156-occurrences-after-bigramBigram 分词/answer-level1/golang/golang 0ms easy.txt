首先对text分词，注意去除多余的空格。然后就是简单的匹配了，当first匹配后， 就去匹配second。 要注意当前idx是否是最后一个值。不然会panic
```
func findOcurrences(text string, first string, second string) []string {
    ts := strings.Split(text, " ")
    tss := make([]string, 0)
    ret := []string{}
    for i := 0; i < len(ts); i++ {
        if ts[i] == "" { // 去除多余的空格
            continue
        }
        tss = append(tss, ts[i])
    }
    for i := 0; i < len(tss); i++ {
        if tss[i] == first {
            // 检查当前idx
            if i+1 < len(tss) && tss[i+1] == second {
                if i+2 < len(tss) {
                    ret = append(ret, tss[i+2])
                }
            }
        }
    }
    return ret
}
```