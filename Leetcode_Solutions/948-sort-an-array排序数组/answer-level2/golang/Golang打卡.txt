### 解题思路
快排

### 代码

```golang
func sortArray(nums []int) []int {
    if len(nums) < 2 {
        return nums
    }
    var (
        helper func(left,right int)
    )
    helper = func(l,r int) {
        if r-l < 1 {
            return
        }
        var (
            cur = nums[l]
            left = l+1
            right = r
        )
        for {
            for right >= l+1 && nums[right] >= cur {
                right --
            }
            for left <= r && nums[left] < cur {
                left ++
            }
            if left >= right {
                break
            }
            nums[left],nums[right] = nums[right],nums[left]
        }
        nums[l],nums[right] = nums[right],nums[l]
        helper(l,right-1)
        helper(right+1,r)
    }
    helper(0,len(nums)-1)
    return nums
}
```