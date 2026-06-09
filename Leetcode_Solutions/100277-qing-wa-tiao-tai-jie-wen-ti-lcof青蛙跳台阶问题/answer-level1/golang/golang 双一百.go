### 解题思路
此同斐波那契. 

分析可知, 在大于两个台阶的时候, 要么选跳一格, 要么选跳两格. 

用 f(n) 表示跳 n 个的办法数量.

那么选择跳一格, 剩下的台阶是 f(n-1) 中方法跳
选择跳两格 , 剩下的台阶是  f(n-2) 的方法跳. 

即 f(n) = f(n-1) + f(n-2)

由于每次计算只需要两个存储空间,可申请 2 元素数组. 

### 代码

```golang
func numWays(n int) int {
   if n == 0 {return 1}
   if n == 1 { return 1}
   dp := make([]int, 2)
   dp[0] = 1;
   dp[1] = 2;
   for i := 3; i<= n ; i++ {
       new := (dp[1] + dp[0])%(1e9+7)
       dp[0] = dp[1]
       dp[1] = new
    } 
    return dp[1]
}
```