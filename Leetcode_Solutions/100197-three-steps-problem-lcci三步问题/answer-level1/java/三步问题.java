### 解题思路
简单的动态规划问题

### 代码

```java
class Solution {
    public int waysToStep(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int [] dp=new int[n+1];
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<n+1;i++)
            dp[i]=((dp[i-1]%1000000007+dp[i-2]%1000000007)%1000000007+dp[i-3]%1000000007)%1000000007;
        return dp[n];
    }
}
```