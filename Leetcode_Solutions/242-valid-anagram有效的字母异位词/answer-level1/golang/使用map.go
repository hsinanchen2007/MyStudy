### 解题思路
此处撰写解题思路

### 代码

```golang
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }

    //遍历s，将每个字符出现的次数存入map
    sm := map[rune]int{}
    for _,v := range(s) {
        if _,ok := sm[v]; ok {
            sm[v] ++
        }else {
            sm[v] = 1
        }
    }

    //遍历t，出现一次，次数减1，当次数为0时，从sm中删除，找不到则返回false
    for _,v := range(t) {
        if _,ok := sm[v]; ok && sm[v] > 0{
            sm[v]--
            if sm[v] == 0 {
                delete(sm,v)
            }
        }else{
            return false
        }
    }

    //如果sm长度为0，则完全匹配，返回true
    if len(sm) == 0 {
        return true
    }

    return false

}
```