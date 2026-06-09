```
func findDuplicate(nums []int) int {
    group:=make(map[int]int)
    for _,v := range nums{
        if _,ok:=group[v];ok{
            return v
        }
        group[v]=1
    }
    return 0
}
```
