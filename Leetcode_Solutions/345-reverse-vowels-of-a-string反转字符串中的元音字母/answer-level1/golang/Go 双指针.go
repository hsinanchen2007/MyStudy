### 解题思路
双指针

### 代码

```golang
//Go语言的单引号一般用来表示rune literal
func reverseVowels(s string) string {
    m := map[byte]bool{
        'a': true,
        'e': true,
        'i': true,
        'o': true,
        'u': true,
        'A': true,
        'E': true,
        'I': true,
        'O': true,
        'U': true,
        }
    if s == "" {
        return s
    }
    i,j:= 0, len(s)-1
    res := make([]byte,len([]byte(s)))
    for i<=j {
        si,sj:= []byte(s)[i],[]byte(s)[j]
        if m[si] != true {
            res[i] = si
            i++
        } else if m[sj] != true {
            res[j] = sj
            j--
        } else {
            res[i] = sj
            res[j] = si
            i++
            j--
        }
    }
    return string(res)
}
```