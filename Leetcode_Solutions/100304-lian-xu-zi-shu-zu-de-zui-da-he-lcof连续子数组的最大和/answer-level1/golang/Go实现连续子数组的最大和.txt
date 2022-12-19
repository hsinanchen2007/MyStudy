
```golang
func maxSubArray(nums []int) int {
    max := nums[0]
    curMax := 0
    for _,v := range nums{
        if curMax>=0{
            curMax+=v
        }else{
            curMax = v
        }
        if curMax>max{
            max = curMax
        }
    }
    return max
}
```