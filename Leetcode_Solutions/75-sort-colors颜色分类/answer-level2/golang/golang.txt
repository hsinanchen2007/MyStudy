```
func sortColors(nums []int)  {
    p1, p2, cur := 0, len(nums) - 1, 0
    temp := 0
    for cur <= p2 {
        if nums[cur] == 0 {
            temp = nums[p1]
            nums[p1], nums[cur] = nums[cur], temp
            p1++
            cur++
        } else if nums[cur] == 2 {
            temp = nums[cur]
            nums[cur], nums[p2] = nums[p2], temp
            p2--
        } else {
            cur++
        }
    }
}
```