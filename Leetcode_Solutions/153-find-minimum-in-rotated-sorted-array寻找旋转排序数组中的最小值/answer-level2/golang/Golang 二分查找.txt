
- 寻找满足 nums[m] < nums[m-1] 的点
- 如果搜索到 m=0 时，特殊考虑
- 没有搜索到代表数组是升序的，则返回 nums[0]

```
func findMin(nums []int) int {
    l := 0
    r := len(nums)-1
    m := 0
    if len(nums) == 1 {
        return nums[0]
    }
    
    for l<=r {
        m = l+(r-l)/2
        if m == 0 {
            if nums[0] > nums[1] {
                return nums[1]
            } else {
                return nums[0]
            }
        }
        if nums[m] < nums[m-1] {
            return nums[m]
        } else if nums[m] > nums[0] {
            l = m+1
        } else {
            r = m-1
        }
    }
    return nums[0]
}
```