### 解题思路
此处撰写解题思路
1、将magazine中的字符出现的次数存到map中
2、遍历ransomNote，然后将字符出现的次数减1
3、如果出现次数小于0的情况出现，那么就false，否则就true

### 代码

```golang
func canConstruct(ransomNote string, magazine string) bool {

    if len(magazine) == 0 {
        if len(ransomNote) == 0 {
            return true
        }
        return false
    }
    if len(ransomNote) > len(magazine) {
        return false
    }

    magazineMap := make(map[string]int)

    for _,v := range magazine {
        magazineMap[string(v)]++
    }

    for _,v := range ransomNote {
        magazineMap[string(v)]--
        if magazineMap[string(v)] < 0 {
            return false
        } 
    }
    return true
}
```