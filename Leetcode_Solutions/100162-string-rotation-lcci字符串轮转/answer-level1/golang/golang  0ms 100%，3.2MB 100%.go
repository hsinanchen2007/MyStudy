
```
func isFlipedString(s1 string, s2 string) bool {
    if s1 == s2 {
        return true
    }
    if !((len(s1) > 0) && (len(s2) > 0)) {
        return false
    }
    
    chs := []byte(s1)
    chsAnother := []byte(s2)
    for i := 0; i < len(chs); i++ {
        ch := chs[0]
        chs = chs[1:]
        chs = append(chs, ch)
        // if s2 == string(chs) {return true} // string() 性能极差
        if bytes.Equal(chs, chsAnother) {return true}
    }
    return false
}
```