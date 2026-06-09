
**不了解斐波那契数列的可以先看我上一题解**

[https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/go-dong-tai-gui-hua-jie-ti-by-sakura-151/](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/go-dong-tai-gui-hua-jie-ti-by-sakura-151/)

---

# 与斐波那契的不同点

如果说题目的要求是计算**至少**有多少种走法，那就跟斐波那契一样
**f(0)=0,f(1)=1,f(n)=f(n-1)+f(n-2)**

但题目问的是**总共**有多少种走法？

---

即转换思路可得：

# 思路一

**因为0个台阶也有一种走法,所以f(0)=1**
**f(0)=1,f(1)=1,f(n)=f(n-1)+f(n-2)**


思路一解法：

--执行用时：0ms   --内存消耗：2MB

```go
func numWays(n int) int {
    if n==0{
        return 1
    }
    if n==2||n==1{
        return n
    }
    dp:=make([]int,n+1)
    dp[0]=1
    dp[1]=1
    for i:=2;i<=n;i++{
        dp[i]=(dp[i-1]+dp[i-2])%1000000007
    }
    return dp[n]
}
```

# 思路二

**2个台阶有两种走法,即f(2)=2**

思路二解法：

--执行用时：0ms   --内存消耗：2MB

```go
func numWays(n int) int {
    if n==0{
        return 1
    }
    if n==2||n==1{
        return n
    }
    dp:=make([]int,n+1)
    dp[1]=1
    dp[2]=2
    for i:=3;i<=n;i++{
        dp[i]=(dp[i-1]+dp[i-2])%1000000007
    }
    return dp[n]
}
```

**--注意：答案需要取模 1e9+7（1000000007），如计算初始结果>1000000008，则返回 1**