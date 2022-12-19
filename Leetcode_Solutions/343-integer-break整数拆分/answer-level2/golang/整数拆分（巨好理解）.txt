# 看了很多评论，自己想出来一个办法
#从1--->10，发现1-6数没有规律，7-10的规律为dp[7]=dp[4]*3,dp[8]=dp[5]*3...,
#验证了到30，依然正确
```
func integerBreak(n int) int {
    if n==1{
        return 1
    }
    //定义状态
    dp:=make([]int,n+1)
    //初始值
    dp[1]=1
    for i:=2;i<=n;i++{
        if i==2{
            dp[i]=1
        }else if i==3{
            dp[i]=2
        }else if i==4{
            dp[i]=4
        }else if i==5{
            dp[i]=6
        }else if i==6{
            dp[i]=9
        }else{
            //从第7项开始有规律
            dp[i]=3*dp[i-3]
        }
    }
    return dp[n]
}
```
#方法有点菜，仅供参考