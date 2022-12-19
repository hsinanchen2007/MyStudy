```golang
func reverseWords(s string) string {
    words := make([]string, 0)
    for i, last := 0, 0; i < len(s); i++ {
        if s[i] == ' '{
            if i == last {
                last++
                continue
            }else if s[last] != ' ' {
                words = append(words, s[last: i])
                last = i + 1
            }
        }
        if last < len(s) && i == len(s) - 1 {
            words = append(words, s[last:])
        }
    }
    sentence := ""
    for i := len(words) - 1; i >= 0; i-- {
        if i == len(words) - 1 {
            sentence += words[i]
        }else{
            sentence += " " + words[i]
        }
    }
    return sentence
}
```
