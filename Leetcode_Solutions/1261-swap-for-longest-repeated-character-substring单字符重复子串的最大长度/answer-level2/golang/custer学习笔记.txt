```go
func maxRepOpt1(text string) int {
    cnt := make(map[byte]int)
    for i := 0; i < len(text); i++ {
        cnt[text[i]]++
    }
    res := 0
    for i := 0; i < len(text); {
        j := i
        for ; j < len(text); j++ {
            if text[j] != text[i] {
                break
            }
        }
        if j-i > res {
            res = j-i
        }
        if j >= len(text) {
            break
        }
        k := j+1
        for ; k < len(text); k++ {
            if text[k] != text[i] {
                break
            }
        }
        tmp := k - i
        if tmp > cnt[text[i]] {
            tmp--
        }
        if tmp > res {
            res = tmp
        }
        i = j
    }
    return res
}
```
