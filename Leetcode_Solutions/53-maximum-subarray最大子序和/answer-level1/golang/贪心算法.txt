### 贪心算法
使用单个数组作为输入来查找最大（或最小）元素（或总和）的问题，贪心算法是可以在线性时间解决的方法之一。
每一步都选择最佳方案，到最后就是全局最优的方案。
### 代码

```golang
func maxSubArray(nums []int) int {
    ln := len(nums)
    if ln == 0 {
        return 0
    }
    pre := nums[0]
    maxSum := pre
    for i:=1;i<ln;i++{
        pre = max(nums[i],pre + nums[i])
        maxSum = max(maxSum,pre)
    }
    return maxSum
}

func max(a,b int)int {
    if a >b {
        return a
    }else {
        return b
    }
}
```