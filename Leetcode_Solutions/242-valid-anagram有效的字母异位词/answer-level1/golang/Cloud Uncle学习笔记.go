1. 将string转换成[]int之后，然后对[]int排序，看两个[]int切片是否相等
```
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }

    sArr := make([]int, len(s))
    tArr := make([]int, len(t))
    for i := 0; i < len(s); i++ {
        sArr[i] = int(s[i] - 'a')
        tArr[i] = int(t[i] - 'a')
    }

    sort.Ints(sArr)
    sort.Ints(tArr)

    for i:=0; i<len(s); i++ {
        if sArr[i] != tArr[i] {
            return false            
        }        
    }
    return true    
}
```

2.map
    定义一个map[byte]int,统计每个字母出现的次数，一个string加count，一个string减count
```
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }

    sMap := make(map[byte]int, len(s))
    for i := 0; i < len(s); i++ {
        sMap[s[i]]++
    }
    for i := 0; i < len(t); i++ {
        if _, exist := sMap[t[i]]; !exist {
            return false
        }
        sMap[t[i]]--
    }
    
    for _, elem := range sMap {
        if elem != 0 {
            return false
        }        
    }

    return true
}
```

```
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }

    sMap := make(map[byte]int, len(s))
    for i := 0; i < len(s); i++ {
        sMap[s[i]]++
        sMap[t[i]]--
    }
    for _, elem := range sMap {
        if elem != 0 {
            return false
        }
    }

    return true    
}
```
