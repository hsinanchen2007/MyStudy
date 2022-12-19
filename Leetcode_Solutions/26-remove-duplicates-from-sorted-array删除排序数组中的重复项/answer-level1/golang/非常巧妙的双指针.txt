时间复杂度:O(n)
空间复杂度:O(1)

```
// 双指针法，快慢指针实现
func removeDuplicates(nums []int) int {
    i,j := 0, 0
    for j = 1; j < len(nums); j++ {
        if nums[j] == nums[i] {
            continue
        }
        i++
        nums[i] = nums[j]
    }
    return i+1
}
```