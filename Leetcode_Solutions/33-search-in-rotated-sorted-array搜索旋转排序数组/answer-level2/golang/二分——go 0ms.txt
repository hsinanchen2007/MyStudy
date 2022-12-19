![image.png](https://pic.leetcode-cn.com/b3767a365d50ce1922969928dd92c61652ff525832a6b0646aed6abf3b92a23a-image.png)

解题思路：旋转排序数组属性：有两段有序数组组成，且第二段的最大值小于第一段的最小值。通过临界值来做判断0 length-1
if target < nums[0] && target > nums[length - 1] 不在数组中
if target >= nums[0] 在第一段数组中 因为target>=nums[0],当碰到nums[i] < target时，到第二段数组 retrn -1
if target <= nums[length - 1] 使用一个临时变量，记录前一个元素值，当碰到nums[i] > tmp时，到第一段数组 return -1
```
func search(nums []int, target int) int {
    length := len(nums)
    if length < 1 {
        return -1
    }
    if length < 2 {
        if nums[0] == target {
            return 0
        }else {
            return -1
        }
    }
    if target < nums[0] && target > nums[length - 1] {
        return -1
    }
    if target >= nums[0] {
        //正序查找
        for i := 0; i < length; i++ {
            if target == nums[i] {
                return i
            }else if target < nums[i] {
                return -1
            }
        }
    }
    if target <= nums[length - 1] {
        //倒序查找
        min := nums[length - 1]
        for j := length - 1; j >= 0; j-- {
            if nums[j] > min {
                return -1
            }
            if target == nums[j] {
                return j
            }else if target > nums[j] {
                return -1
            }
        }
    } 
    return -1
}
```
