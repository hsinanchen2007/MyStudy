**注意：答案需要取模 1e9+7（1000000007），如计算初始结果>1000000007，则返回 1。**

**解题思路放在最后面解释**

# 解法一：动态规划

**写法一:**

**--执行用时：0 ms --内存消耗：2 MB**


```golang
func fib(n int) int {
    if n==0 ||n==1{
        return n
    }
    dp:=make([]int,n+1)
    dp[0]=0
    dp[1]=1
    for i:=2;i<=n;i++{
        dp[i]=(dp[i-1]+dp[i-2])%1000000007
    }
    return dp[n]
}
```

**写法二：**

**--执行用时：0 ms --内存消耗：1.9 MB**

```go
func fib(n int) int {
    if n==0 ||n==1{
        return n
    }
    var (
        a=0
        b=1
        temp int
    )
    for i:=2;i<=n;i++{
        temp = b
        b = (a + b)%1000000007
        a = temp
    }
    return b
}
```

# 解法二：递归（递归会报“超出时间限制”）

```go
func fib(n int) int {
    if n==0 || n==1{
        return n
    }
    return fib(n-1)+fib(n-2)
}
```

# 解法一的解题思路

**1.什么是动态规划？**
**简单来讲就是一个问题的子问题的结果会被重复利用，也是一种递归思想。**

**2.假设n=5**

可得：

![斐波那契图示.png](https://pic.leetcode-cn.com/39c01d50298a9ac641d2efb2c85f811cccf38ccbedf49c1605f3695a3d2b74f7-%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E5%9B%BE%E7%A4%BA.png)



