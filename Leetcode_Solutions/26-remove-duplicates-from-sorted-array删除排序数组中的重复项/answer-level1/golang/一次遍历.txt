```
func removeDuplicates(nums []int) int {
    n := len(nums)
    if n < 2 {
        return n
    } else {
        flag := 0
        tmp := nums[0]
        i := 1
        for ; i < n; i++ {
            if nums[i] != tmp {
                tmp = nums[i]
                nums[i-flag] = tmp
            } else {
                flag++
            }
        }
        return i - flag
    }
}
```
