### 解题思路
申请 101 元素数组
把每一个元素的值填入即可. 

减少了每一次的递归运算

### 代码

```golang
func fib(n int) int {
    var dp  = make([]int, 101)
    dp[0] = 0 ;
    dp[1] = 1 ;
    for i := 2; i<= n ; i++ {
        dp[i] = (dp[i-1] + dp[i-2])%(1e9+7)
    }
    return dp[n]
}
```