

```golang
func firstUniqChar(s string) byte {
    res := make([]int,26)
    for _,v := range s{
        res[v-'a']++
    }
    for _,v := range s{
        if res[v-'a']==1{
            return byte(v)
        }
    }
    return ' '
}
```