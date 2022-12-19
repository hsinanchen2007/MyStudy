### 解题思路
此处撰写解题思路

### 代码

```golang
func rob(nums []int) int {
    if len(nums)==0{
        return 0
    }
    if len(nums)==1{
        return nums[0]
    }
    dp:=make([]int,len(nums)+1)
    dp[0]=0
    dp[1]=nums[0]
    for i:=2;i<=len(nums);i++{
        
            
       if dp[i-1]>nums[i-1]+dp[i-2]{
            dp[i]=dp[i-1]
       }else{
            dp[i]=nums[i-1]+dp[i-2]
       }
        //fmt.Println(dp[i])
        
    }
    if dp[len(nums)]>dp[len(nums)-1]{
        return dp[len(nums)]
    }
    return dp[len(nums)-1]
}
```