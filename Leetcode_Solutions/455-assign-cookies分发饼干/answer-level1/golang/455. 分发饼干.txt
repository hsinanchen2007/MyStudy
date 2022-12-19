```
func findContentChildren(g []int, s []int) int {
    var child, cookie int
    sort.Ints(g)
    sort.Ints(s)
    //当一个遍历完，就结束
    for child < len(g) && cookie < len(s){
        if g[child] <= s[cookie]{
            child++
        }
        cookie++
    }
    return child
}
```
