hashtable & two point
```
func minWindow(s string, t string) string {
    m := make(map[byte]int)
    tlen, slen := len(t), len(s)
    for i := 0; i < tlen; i++ {
        m[t[i]]++
    }
    hit, start, minlen, res := 0, 0, slen, ""
    for j := 0; j < slen; j++ {
        m[s[j]]--
        if  m[s[j]] >= 0 {
            hit++
        }
        for hit == tlen {
            if  minlen > j - start {
                minlen = j - start
                res = s[start:j+1]
            }
            m[s[start]]++
            if m[s[start]] > 0 {
                  hit--
            }
            start++
        }
    }
    return res
}
```
