### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int integerBreak(int n) {
        if(n==1) return 1;
        if(n==2) return 1;
        if(n==3) return 2;//这几种情况是自身大于分解，所以拆到1，2，3就不需要分解了，4以后大于自身
        int [] dp = new int[n+1];
        for(int i=1;i<=n;i++){
            dp[i] = i;//不拆分得话就是i，拆分的话只会比dp[i]大，所以先给个不拆分的情况
            for(int j=0;j<i;j++){//拆分得话拆j个就是j*dp[i-j]
                dp[i] = Math.max(dp[i],j*dp[i-j]);
            }
        }
        return dp[n];
    }
}
```