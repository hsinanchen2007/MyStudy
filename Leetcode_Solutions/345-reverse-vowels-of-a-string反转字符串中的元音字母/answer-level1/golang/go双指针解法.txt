
func reverseVowels(s string) string {
    if s == "" {
        return ""
    }
    vowels := make(map[byte]int)
    for i, v := range "aeiouAEIOU" {
        vowels[byte(v)] = i
    }

    length := len(s)
    i, j := 0, length-1
    
    var result = make([]byte, length)
    for i <= j {
        ci := s[i]
        cj := s[j]
        if _, ok := vowels[ci]; !ok {
            result[i] = ci
            i++
        }else if _, ok := vowels[cj]; !ok {
            result[j] = cj
            j--
        }else {
            result[i] = cj
            i++
            result[j] = ci
            j--
        }
    }
    return string(result)
}