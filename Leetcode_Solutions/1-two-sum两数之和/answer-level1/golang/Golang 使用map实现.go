### 解题思路

通过查找 target 与当前值的差值是否在 map 中，快速找出匹配的元素，时间复杂度为 O(n)

### 代码

```golang
func twoSum(nums []int, target int) []int {
    existed := make(map[int]int)

    for i := 0; i < len(nums); i++ {
        if ex, ok := existed[target - nums[i]]; ok {
            return []int{i, ex}
        }

        existed[nums[i]] = i
    }

    return nil
}
```