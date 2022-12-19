### 解题思路
此处撰写解题思路

### 代码

```golang
func sortColors(nums []int)  {
    left, cur, right := 0, 0, len(nums) - 1
    for cur <= right {
        if nums[cur] == 0 {
            nums[cur], nums[left] = nums[left], nums[cur]
            cur += 1
            left += 1
        } else if nums[cur] == 1 {
            cur += 1
        } else {
            nums[cur], nums[right] = nums[right], nums[cur]
            right -= 1
        }
    }
}
```