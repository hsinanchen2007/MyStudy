把数组中小于数组大小的值，放到对应的数组位置，之后遍历数组，发现index 和v不匹配表示缺失的值
```
func firstMissingPositive(nums []int) int {
    for i:=0;i<len(nums); {
        if nums[i] <= len(nums) && nums[i] > 0 && nums[i] != nums[nums[i] - 1] {
            nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
        }else {
            i++
        }
    }
    for idx,v := range nums {
        if idx+1 != v {
            return idx+1
        }
    }
    return len(nums) + 1
}
```
