### 解题思路
一次循环让除了n之外的数字都回到正确位置，最后n在哪就缺哪个数字
### 代码

```golang
func missingNumber(nums []int) int {
    // 一次循环让除了n之外的数字都回到正确位置，最后n在哪就缺哪个数字
    n := len(nums)
    // 默认没有n的位置
    idx := n
    for i := 0; i < n; {
        if nums[i] == n {
            idx = i
            i++
            continue
        }
        if i == nums[i] {
            i++
            continue
        }
        nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
    }
    return idx
}
```