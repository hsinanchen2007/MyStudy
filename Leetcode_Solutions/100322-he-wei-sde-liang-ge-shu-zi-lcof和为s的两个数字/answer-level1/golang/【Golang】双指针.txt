# 解题思路
- 因为**数组是递增序列**，定义首位双指针，left 和 right
- 先用for循环或者二分法将大于目标值的数字全都排除
-  **for  left < right 循环判断**
 	- 双指针对应的数字相加等于目标值，返回双指针对应的数字
 	 	- nums[left]+nums[right]==target
 	 - 否则
 	 	- 当 nums [ left ] > target - nums [ right ] 时，说明右边的值过大，right - 1
 	 	- 当 nums [ left ] < target - nums [ right ] 时，说明左边的值过小，left + 1
 	- 同理有:
 	 	- 当 nums [ right ] > target - nums [ left ] 时，说明右边的值过大，right - 1
 	 	- 当 nums [ right ] < target - nums [ left ]时，说明左边的值过小，left + 1
 	 - 这里选择一种情况写即可，否则会出现错误
---
# 代码

--执行用时：220 ms --内存消耗：10.4 MB
```go
func twoSum(nums []int, target int) []int {
    if nums==nil || len(nums)<2 {
        return nil
    }
    left:=0
    right:=len(nums)-1
    //大于目标值的数字全都排除
    for nums[right]>target{
            right--
    }
    for left<right{
        if nums[left]+nums[right]==target{
            return []int{nums[left],nums[right]}
        }
        if nums[left]>target-nums[right]{
            right--
        }else{
            left++
        }
        //同理有，这里选择一种情况写即可，否则会出现错误
        /*
        if nums[right]>target-nums[left]{
            right--
        }else{
            left++
        }
        */
    }
    return nil
}
```