二分题，首先排序，然后比较每一位是否相同，不同就+1
```
func heightChecker(heights []int) int {
    t := make([]int, len(heights))
    copy(t, heights)
    sort.Ints(t)
    diff := 0
    for i := 0; i < len(t); i++ {
        if t[i] != heights[i] {
            diff++
        }
    }
    return diff
}
```