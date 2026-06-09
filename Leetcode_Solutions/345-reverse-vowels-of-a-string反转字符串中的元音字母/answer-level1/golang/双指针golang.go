func reverseVowels(s string) string {
    m := map[byte]bool{
        'a': true,'A': true,
        'e': true,'E': true,
        'i': true,'I': true,
        'o': true,'O': true,
        'u': true,'U': true,
    }
    t_s := []byte(s) 
    i:=0
    j:=len(s)-1
    for i < j {
        if _, v := m[t_s[i]]; !v {
            i++
            continue
        }

        if _, v := m[t_s[j]]; !v {
            j--
            continue
        }
        t_s[i],t_s[j] = t_s[j],t_s[i]
        i++
        j--
    }
    return string(t_s)
}