```
func canConstruct(ransomNote string, magazine string) bool {    // hash 表
    hash := make(map[rune]int)
    for _,x := range magazine {    // 记录第二个字符串magazines里面的字符构成
        hash[x]++
    }
    for _,x := range ransomNote {  // 判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成
        if hash[x] == 0 {
            return false
        } else {
            hash[x]--
        }
    }
    return true
}
```