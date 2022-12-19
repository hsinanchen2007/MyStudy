```go
func checkInclusion(s1 string, s2 string) bool {
    if len(s2)<len(s1){return false}
    var cnt1,cnt2 [26]int
    for i:=0;i<len(s1);i++ {
        cnt1[s1[i]-'a']++
        cnt2[s2[i]-'a']++
    }
    if cnt1==cnt2 {return true}
    for i,j:=len(s1),0;i<len(s2);i++{
        cnt2[s2[i]-'a']++
        cnt2[s2[j]-'a']--
        j++
        if cnt1==cnt2 {return true}
    }
    return false
}
```
