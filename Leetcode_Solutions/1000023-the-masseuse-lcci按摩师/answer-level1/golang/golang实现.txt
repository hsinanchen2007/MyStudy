打家劫舍换了个描述，dp[i]=max(dp[i-1], dp[i-2]+nums[i])

```golang
func massage(nums []int) int {
    if len(nums)==0{
        return 0
    }
    dp:=make([]int,len(nums)+1)
    dp[0]=0
    dp[1]=nums[0]
    for i:=1;i<len(nums);i++{
        dp[i+1]=max(dp[i],dp[i-1]+nums[i])
    }
    return dp[len(nums)]
}

func max(i,j int)int{
    if i>j{
        return i 
    }
    return j 
}
```