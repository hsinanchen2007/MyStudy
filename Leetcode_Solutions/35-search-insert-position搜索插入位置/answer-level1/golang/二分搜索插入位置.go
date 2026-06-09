### 解题思路
标准的二分查找问题；参考了https://leetcode-cn.com/u/liweiwei1419/的方法，很棒的博主

### 代码

```golang
func searchInsert(nums []int, target int) int {
        if nums == nil { 
        return -1
    }
    
    left, right := 0, len(nums)  // 目标值有可能大于数组中的最大值，右边界需要包含len(nums)
    // 查找部分和标准二分完全一致
    for left < right {
        mid := left + ((right - left) >> 1)
        if nums[mid] < target {
            left = mid + 1
        } else {
            right = mid 
        }
    }
    return left
}
```