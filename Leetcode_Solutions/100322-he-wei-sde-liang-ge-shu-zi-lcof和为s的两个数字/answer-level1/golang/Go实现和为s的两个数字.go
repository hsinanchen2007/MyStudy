

```golang
func twoSum(nums []int, target int) []int {
    if nums == nil || len(nums)<2{
        return nil
    }
    left,right := 0,len(nums)-1
    for left<right{
        if nums[left]+nums[right]>target{
            right--
        }else if nums[left]+nums[right]<target{
            left++
        }else{
            return []int{nums[left],nums[right]}
        }
    }
    return []int{}
}
```