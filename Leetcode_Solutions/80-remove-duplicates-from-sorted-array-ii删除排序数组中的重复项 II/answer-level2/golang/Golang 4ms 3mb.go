### 解题思路
此处撰写解题思路

### 代码

```golang
func removeDuplicates(nums []int) int {
    if len(nums) <= 2 {
        return len(nums)
    }
    count := 1
    for i := 1; i < len(nums); {
        if nums[i] == nums[i-1] {
            count += 1
        } else {
            count = 1
        }
        if count > 2 {
            nums = append(nums[:i], nums[i+1:]...)
            count -= 1
        } else {
            i += 1
            continue
        }
    }
    return len(nums)
}
```