### 解题思路
* dp[i] 表示当前以i结尾的数组乘积最大的子序列
* 由于遇到负数会发生跳变 这种跳变是因为 负数将之前的最小值变成了最大值,最大值反而成为了最小值
* 因此dp方程为 `dp[i] = max(dp[i-1],maxDp[i])`
* 其中 `maxDp[i] = if nums[i] < 0  max(nums[i]*minDp[i-1],nums[i]) else max(nums[i]*maxDp[i-1],nums[i])`
* 其中 `minDp[i] = if nums[i] < 0  min(nums[i]*maxDp[i-1],nums[i]) else min(nums[i]*minDP[i-1],nums[i])`
* 不难看出本质上 其简化后就 当nums[i] < 0 时 最大值与最小值交换了位置 因此可以将代码进一步简化处理
* 并且根据三个dp数组的动态方程可以进一步优化为 全局结果,最大值,最小值 三个变量来实现

### 代码

```golang
func maxProduct(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    if len(nums) == 1 {
        return nums[0]
    }
   imax,imin,res := nums[0],nums[0],nums[0]
   for i := 1; i < len(nums); i++{
       if nums[i] < 0{
           imax, imin = imin, imax
       }
       imax = max(nums[i]*imax,nums[i])
       imin = min(nums[i]*imin,nums[i])
       res = max(res,imax)
   }
   return res
}
func max(a,b int)int{
    if a > b{
        return a
    }else{
        return b
    }
}
func min(a,b int)int{
    if a > b{
        return b
    }else{
        return a
    }
}
```