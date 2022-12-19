### 解题思路
此处撰写解题思路

### 代码

```golang
func maxSubArray(nums []int) int {
    
    dp:=make([]int,len(nums)+1)
    dp[0]=0
    for i:=1;i<len(nums)+1;i++{
        dp[i]=max(dp[i-1]+nums[i-1],nums[i-1])
    }
    dd:=math.MinInt64
    for i:=1;i<len(nums)+1;i++{
        dd=max(dd,dp[i])
    }
    return dd
}
func max(i, j int)int{
    if i>j{
        return i
    }
    return j
}
```