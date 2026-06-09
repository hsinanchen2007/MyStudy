```
func exchange(nums []int) []int {
    ret := make([]int, len(nums))
    start, end := 0, len(nums) - 1
    for _, v := range nums {
        if v%2 == 1 {
            ret[start] = v
            start++
        } else {
            ret[end] = v
            end--
        }
    }
    return ret
}
```
