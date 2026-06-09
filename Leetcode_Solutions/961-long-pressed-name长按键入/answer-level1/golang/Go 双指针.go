```
func isLongPressedName(name string, typed string) bool {
    if len(typed) < len(name) {
        return false
    }
    i, j := 0, 0
    pre := name[0] 
    for i<len(name) && j<len(typed){
        if typed[j] != name[i] && typed[j] != pre {
            return false
        }
        if typed[j] != name[i] && typed[j] == pre {
            j++
        }else {
            pre = name[i]
            i++
            j++
        }
    }
    if i < len(name) {
        return false
    }
    return true
}
```
