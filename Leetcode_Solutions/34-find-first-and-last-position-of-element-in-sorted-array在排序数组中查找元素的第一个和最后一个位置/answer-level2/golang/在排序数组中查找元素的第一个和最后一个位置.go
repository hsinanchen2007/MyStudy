
## 思路

二分查找细节，先找左边界，再找右边界，其中若找不到左边界，即可判定找不到

```
func searchRange(nums []int, target int) (result []int) {
    n := len(nums)
    result = []int{-1, -1}
    if n == 0 {
        return
    }
    l := left_bound(nums, target)
    if l >= n || nums[l] != target {
        return
    }
    result[0] = l
    result[1] = right_bound(nums, target)
    
    return
}

func left_bound(nums []int, target int) int {
    var left = 0
    var right = len(nums) // 注意
    
    for left < right { // 注意
        var mid = (left + right) / 2
        if nums[mid] < target {
            left = mid + 1
        } else {
            right = mid // 注意
        }
    }
    return left
}

func right_bound(nums []int, target int) int {
    var left = 0
    var right = len(nums) // 注意
    
    for left < right {
        var mid = (left + right) / 2
        if nums[mid] > target {
            right = mid
        }else {
            left = mid + 1
        }  
    }
    return left-1 // 注意

}
```
