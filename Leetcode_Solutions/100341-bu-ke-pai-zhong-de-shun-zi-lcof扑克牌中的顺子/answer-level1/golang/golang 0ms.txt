排序，然后计算总的差值。
差值 小于 5，成立
```
func isStraight(nums []int) bool {
    sort.Ints(nums)
    sub := 0
    for i := 0; i < 4; i++ {
        if nums[i] == 0 {
            continue
        }
        if nums[i+1] == nums[i] {
            return false
        }
        sub += nums[i+1] - nums[i]
    }
    return sub <= 4
}
```
