采用异或的思路 相同的整型异或后得0
```
func singleNonDuplicate(nums []int) int {
    res := 0
    for _, v := range nums {
        res = res ^ v
    }
    return res
}
```