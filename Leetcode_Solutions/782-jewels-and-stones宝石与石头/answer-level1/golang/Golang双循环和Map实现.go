解答一：
直接双循环
```
func numJewelsInStones(J string, S string) int {
    count := 0
    for _, v := range J {
        for _, v1 := range S {
            if rune(v) == rune(v1) {
                count ++
            }
        }
    }
    return count
}
```

解答二：
利用Map实现
```
func numJewelsInStones(J string, S string) int {
    count := 0
    jmap := make(map[rune]int)
    for _, v := range J {
        jmap[v] = 1
    }
    for _, v := range S {
        if _, ok := jmap[v]; ok {
            count++
        }
    }
```

