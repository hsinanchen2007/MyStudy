### 代码

```golang
func search(nums []int, target int) int {
    if len(nums)==0{
        return 0
    }
    lo,hi:=0,len(nums)-1
    mid:=(lo+hi)/2
    for{
        if nums[mid]==target{
            break
        }else if nums[mid]<target{
            lo=mid+1
            mid=(lo+hi)/2
        }else{
            hi=mid-1
            mid=(lo+hi)/2
        }
        if lo>hi{
            return 0
        }
    }
    count:=1
    for i:=mid+1;i<len(nums)&&nums[i]==target;i++{
        count++
    }
    for i:=mid-1;i>=0&&nums[i]==target;i--{
        count++
    }
    return count
}
```