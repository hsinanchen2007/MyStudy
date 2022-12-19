### 解题思路
此处撰写解题思路

### 代码

```golang
func lengthOfLIS(nums []int) int {
    if len(nums) < 2{
        return len(nums)
    }
    dp := []int{}
    for i,v := range nums{
        if i == 0{
            dp = append(dp,1)
            continue
        }
        maxlength := 0
        for j:=0;j<i;j++{
            if v > nums[j] && dp[j] > maxlength{
                maxlength = dp[j]
            }
        }
        dp = append(dp,maxlength + 1)
    }
    res := 0
    for _,x := range dp{
        if x > res{
            res = x
        }
    }
    return res
}
```