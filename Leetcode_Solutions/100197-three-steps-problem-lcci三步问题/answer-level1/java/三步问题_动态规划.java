### 解题思路
分析最后一次的跳法  
如果跳一阶则有 f(n-1)种跳法  
如果跳2阶 则有 f(n-2)中跳法  
如果跳三阶 f(n-3)  
所以总共有 f(n-1)+f(n-2)+f(n-3)种跳法  

### 代码

```java
class Solution {
    public int waysToStep(int n) {
        /*
        这道题是剑指offer中斐波那契数列的变形
        方法一：使用递归
        分析最后一次的跳法
        如果跳一阶则有 f(n-1)种跳法
        如果调2阶 则有 f(n-2)中
        如果调三阶 f(n-3)
        所以总共有 f(n-1)+f(n-2)+f(n-3)种跳法


        if(n<=0){
            return 0;
        }
        int res[]={1,2,4};
        if(n<=3)
            return res[n-1];
        return waysToStep(n-1)+waysToStep(n-2)+waysToStep(n-3);
        重复计算过多，会超过时间限制
        会超出时间限制

        f(1)=1;
        f(2)=2;
        f(3)=4;
        
        方法二：使用动态规划
        一直因为溢出代码通不过，注意取模的方式
        dp[i]=((dp[i-1]%mod+dp[i-2]%mod)%mod+dp[i-3]%mod)%mod;

        */



        if(n<=0)
            return -1;
        
        int res[]={1,2,4};
        if(n<=3)
            return res[n-1];
        
        final int mod = 1000000007;
        int[] dp=new int[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
       
        if(n<=3)
            return dp[n];
        for(int i=4;i<=n;i++){
            dp[i]=((dp[i-1]%mod+dp[i-2]%mod)%mod+dp[i-3]%mod)%mod;
        }
        return dp[n];
    }
}
```