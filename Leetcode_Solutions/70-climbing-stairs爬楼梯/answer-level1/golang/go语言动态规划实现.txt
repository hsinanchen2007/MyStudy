
第一次直接记录每个台阶所需要的步数，然后返回最后一步的步数

```
func climbStairs(n int) int {
    if n <= 2 {
        return n
    }
    var temp = make([]int, n+1)
    temp[1] = 1
    temp[2] = 2
    for i := 3; i <= n; i++ {
        temp[i] = temp[i-1] + temp[i-2]
    }
    return temp[n]
}
```
执行发现消耗内存较大，所以只用两个变量记录上两次的值用于下次计算
```
func climbStairs(n int) int {
 if n <= 2 {
        return n
    }
    dp1, dp2 := 1, 2
    for i := 3; i <= n; i++ {
        dp1, dp2 = dp2, dp1+dp2
    }
    return dp2
}
```
发现内存消耗优化了一点点，区别不大。
应该是case的设置上都比较小