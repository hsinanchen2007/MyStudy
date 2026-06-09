当n为1或2时，可以直接返回结果；其他情况都是根据前两个结果来计算出来的，所以只需要保存前两个结果。
故时间复杂度是 __O(n)__, 空间复杂度为 __O(1)__ ，

```go
func climbStairs(n int) int {
    switch n {
    case 1:
        return 1
    case 2:
        return 2
    default:
        dp1, dp2 := 1, 2
        for i := 2; i < n; i++ {
            dp1, dp2 = dp2, dp1+dp2
        }
        return dp2
    }
}
```