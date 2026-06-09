
![image.png](https://pic.leetcode-cn.com/1a51d38199a034cdf276d4c3395cfc4061bb8ad1aeb7654ad647549a03fbfd62-image.png)
```
func isIsomorphic(s string, t string) bool {
    smap := make(map[byte]byte)
    tmap := make(map[byte]byte)
    ls := len(s)
    lt := len(t)
    if ls == 0 && lt == 0 {
        return true
    }
    if ls != lt {
        return false
    }
    ret := true
    for i:=0 ;i<ls; i++ {
        _, ok1 := smap[s[i]]
        _, ok2 := tmap[t[i]]
        if !ok1 && !ok2 {
            smap[s[i]] = t[i]
            tmap[t[i]] = s[i]
        } else if ok1 && smap[s[i]] == t[i] {
            continue
        } else {
            ret = false
            break
        }
    }
    //fmt.Println(smap, tmap)
    return ret
}
```