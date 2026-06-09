### 解题思路
构造一个nums[i] = i的数组

### 代码

```golang
func findRepeatNumber(nums []int) int {
    cur := 0
    n := len(nums)
    for cur < n{
        if nums[cur] == cur{
            cur++
        }else if nums[cur] == nums[nums[cur]]{
            return nums[cur]
        }else{
            nums[cur],nums[nums[cur]] = nums[nums[cur]],nums[cur]
        }
    }
    return -1
}
```