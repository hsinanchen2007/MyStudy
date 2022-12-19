### 解题思路
1.动态规划中要先找到可变参数n,n值不同，则返回的最大乘积数不同，所以依赖关系就是不同的n值之间dp[]值。
2.先大概算出前几个dp[n],找到规律，

### 代码

```java
class Solution {
    public int integerBreak(int n) {
        int[] dp=new int[n+1];
        if(n==2) return 1;
        if(n==3) return 2;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i]=Math.max(dp[i],dp[i-j]*dp[j]);
            }
        }
        return dp[n];
    }
}
```