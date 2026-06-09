### 解题思路
此处撰写解题思路

### 代码

```golang
func wiggleMaxLength(nums []int) int {
    if len(nums)<2{
        return len(nums)
    }
    if len(nums)==2{
        return 1
    }
    
    dp:=make([]int,len(nums)+1)
    dp1:=make([]int,len(nums)+1)
    for i:=1;i<len(nums);i++{
        for j:=0;j<i;j++{
            //fmt.Println(nums[i-1],nums[j-1])

            //ss:=nums[i-1]-nums[j-1]
            if nums[i]>nums[j]{
                dp1[i]=max(dp[j]+1,dp1[i])
            }else if nums[i]<nums[j]{
                dp[i]=max(dp1[j]+1,dp[i])
            }
        }
    }
    return max(dp[len(nums)-1],dp1[len(nums)-1])+1
}
func max(i,j int)int{
    if i>j{
        return i
    }
    return j
}
```