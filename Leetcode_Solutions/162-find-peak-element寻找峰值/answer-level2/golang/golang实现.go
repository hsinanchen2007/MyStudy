```
//局部最大
func findPeakElement(nums []int) int {
    if len(nums) == 0{//数组为空
        return -1
    }
    
    if len(nums) == 1 || nums[0] > nums[1] {
        return 0
    }
    
    if nums[len(nums) - 1] > nums[len(nums) - 2] {
        return len(nums) - 1
    }
    
    //开始二分
    l := 1
    r := len(nums) - 2
    
    for l <= r {
        mid := l + ((r - l) >> 1)
        if nums[mid] < nums[mid + 1] {
            l = mid + 1
        } else if nums[mid] < nums[mid - 1] {
            r = mid - 1
        } else {//nums[mid] > nums[mid -1] && nums[mid] > nums[mid + 1]
            return mid
        }
    }
    return -1
}
```
