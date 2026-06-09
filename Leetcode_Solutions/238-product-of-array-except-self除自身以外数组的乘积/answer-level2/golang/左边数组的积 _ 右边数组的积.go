```
// 左边数组的积 * 右边数组的积
// dp记录后缀数组乘积
// dp[i] = nums[i+1]*nums[i+2]*...*nums[len(nums)-1]
func productExceptSelf(nums []int) []int {
    if nums == nil || len(nums) == 0 {
        return nil
    }
    n := len(nums)
    dp := make([]int,n)
    dp[n-1] = 1
    for i:=n-2;i>=0;i-- {
        dp[i] = dp[i+1] * nums[i+1]
    }
    pre := 1
    for i:=0;i<n;i++{
        dp[i] = pre * dp[i]
        pre *= nums[i]
    }
    return dp
}
```
