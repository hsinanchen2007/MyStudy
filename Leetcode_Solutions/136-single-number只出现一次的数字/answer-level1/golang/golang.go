```
func singleNumber(nums []int) int {
    var res int
    for _, n := range nums{
        res = n ^ res
    }
    return res
}
```