```
func searchRange(nums []int, target int) []int {
    //1. 寻找左边界
    l := 0
    r := len(nums) - 1

    for l <= r {
        mid := l + ((r - l) >> 1)
        if nums[mid] >= target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    //此时如果数组中有target的话，l 就是左边界
    if l >= len(nums) || nums[l] != target {
        return []int{-1, -1}
    }

    
    l1 := 0
    r1 := len(nums) - 1
    for l1 <= r1 {
        mid := l1 + ((r1 - l1) >> 1)
        if nums[mid] <= target {
            l1 = mid + 1
        } else {
            r1 = mid - 1
        }
    }

    //此时如果数组中有target的话，r1 就是右边界
    
    return  []int{l, r1}
}
```
