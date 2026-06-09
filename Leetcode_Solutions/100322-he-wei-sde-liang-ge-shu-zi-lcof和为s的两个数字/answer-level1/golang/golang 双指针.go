### 解题思路
有序，所以直接上双指针不用hash法。

### 代码

```golang
func twoSum(nums []int, target int) []int {
    var res []int
    if len(nums) <= 1 {
        return res
    }
    l, r := 0, len(nums) - 1
    for l < r {
        if nums[l] + nums[r] > target {
            r--
            continue
        } else if nums[l] + nums[r] < target {
            l++
            continue
        } else {
            res = []int{nums[l], nums[r]}
            break
        }
    }
    return res
}
```