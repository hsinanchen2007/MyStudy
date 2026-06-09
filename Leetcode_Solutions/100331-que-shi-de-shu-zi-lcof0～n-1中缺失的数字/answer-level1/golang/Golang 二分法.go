### 代码

```golang
func missingNumber(nums []int) int {
    lo,hi:=0,len(nums)-1
    mid:=(lo+hi)/2
    for{
        if lo>hi{
            return lo
        }else if mid!=nums[mid]{
            hi=mid-1
            mid=(lo+hi)/2
        }else{
            lo=mid+1
            mid=(lo+hi)/2
        }
    }
    return lo
}
```