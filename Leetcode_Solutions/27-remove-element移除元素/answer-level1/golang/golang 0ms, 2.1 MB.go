```
func removeElement(nums []int, val int) int {
    for i := 0; i < len(nums); {
        if nums[i] == val {
            nums = append(nums[:i], nums[i+1:]...)
        } else {
            i = i + 1
        }
    }
    return len(nums)
}
```