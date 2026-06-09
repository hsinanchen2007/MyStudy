

```golang
func missingNumber(nums []int) int {
    l,r := 0,len(nums)-1
    for l<=r{
        mid := l+(r-l)/2
        if nums[mid]==mid{
            l=mid+1
        }else{
            if mid==0 || nums[mid-1]==mid-1{
                return mid
            }
             r = mid-1
        }
    }
    if l ==len(nums){
        return l
    }
    return -1
}
```