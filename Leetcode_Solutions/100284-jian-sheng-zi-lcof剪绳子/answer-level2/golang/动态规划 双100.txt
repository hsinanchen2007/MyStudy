### 解题思路
考虑题目的问题模式 考虑是动态规划
发现dp[i] = max(dp[k]*dp[i-k],i-k)
其中有那么算到dp[n],返回dp[n]即可

### 代码

```golang
func cuttingRope(n int) int {

    //建成m段 组合数
    if n<=1{
        return 0
    }
    dp = make([]int,n+1)
    dp[1] = 1
    dp[2] = 1
    for i:=2;i<=n;i++{
        dp[i] = cal(i) 
    }
    return dp[n]
}

//f()*
func cal(m int) int {
     max:=0
     end:=(m+1)/2
     for i:=1;i<=end;i++{
         if dp[m-i]<m-i{
             dp[m-i] = m -i
         }
         sum := dp[i]*dp[m-i]
         if max <sum{
             max = sum
         }
     }
     return max
}

var dp []int
```