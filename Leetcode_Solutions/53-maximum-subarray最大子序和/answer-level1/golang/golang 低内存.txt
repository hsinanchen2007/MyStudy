//dp算法：定义f(n)=max(f(n-1),num[n])
func maxSubArray(nums []int) int {
    if len(nums) <= 0{
        return 0
    }
    _max:=nums[0]
    for i:=1;i<len(nums);i++{
        nums[i]=max(nums[i],nums[i]+nums[i-1])
        if nums[i]>_max{
            _max=nums[i]
        }
    }
    return _max
}

func max(a,b int)int{
    if a>b {
        return a 
    }
    return b
}