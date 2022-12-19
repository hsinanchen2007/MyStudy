```
func permutation(S string) []string {
    res := make([]string, 0)
    ss := []rune(S)
    sLen := len(ss)

    used := [9]bool{}
    stack := make([]rune, 0)

    for i:=0; i<sLen; i++ {
        if used[i] {
            continue
        }
        used[i] = true
        stack = []rune{used[i]}

        for j:=1; j<sLen; j++ {
            
        }
    }

    return res
}
```
