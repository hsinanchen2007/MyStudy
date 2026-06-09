

```golang
func findMin(nums []int) int {
      l,r := 0,len(nums)-1
    for nums[l]>=nums[r] && l<r{
        mid := l+(r-l)/2
        if nums[mid]>nums[l]{
            l=mid+1
        }else if nums[mid]<nums[l]{
            r = mid
        }else{
            l++
        }
    }
    return nums[l]
}


```