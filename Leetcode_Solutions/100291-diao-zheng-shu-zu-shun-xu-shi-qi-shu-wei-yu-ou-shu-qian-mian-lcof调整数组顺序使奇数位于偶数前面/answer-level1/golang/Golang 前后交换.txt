### 解题思路
28ms 6MB
两个下标, 一个从前向后扫描奇数, 一个从后向前扫描偶数, 并交换

### 代码

```golang
func exchange(nums []int) []int {
    left, right := 0, len(nums)-1
    for left < right {
        if nums[left] & 1 == 0 && nums[right] & 1 == 1 {
            nums[left], nums[right] = nums[right], nums[left]
        } else if nums[left] & 1 == 0 {
            right--
        } else if nums[right] & 1 == 1 {
            left++
        } else {
            left++
            right--
        }
    }
    return nums
}
```