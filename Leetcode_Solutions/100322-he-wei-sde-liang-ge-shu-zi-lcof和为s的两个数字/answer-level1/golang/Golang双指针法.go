### 代码

```golang
func twoSum(nums []int, target int) []int {
    lo,hi:=0,len(nums)-1
    for{
        sum:=nums[lo]+nums[hi]
        if sum==target{
            return []int{nums[lo],nums[hi]}
        }else if sum<target{
            lo++
        }else{
            hi--
        }
    }
    return nil
}
```