执行耗时 0ms
使用内存2.2M


```
func numJewelsInStones(J string, S string) int {
    jMap := map[string]int{}
    jRune := []rune(J)
    sRune := []rune(S)
    for _, j := range jRune{
        jMap[string(j)] = 0
    }
    
      for _, s := range sRune{
          if _, ok := jMap[string(s)] ; ok {
              jMap[string(s)] += 1
          }
    }
    
    var sum int
     for _, j := range jRune{
         sum += jMap[string(j)]
    }
    return sum
}
```
