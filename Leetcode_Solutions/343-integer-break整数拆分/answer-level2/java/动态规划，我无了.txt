### 解题思路
此处撰写解题思路
由小及大，从2到n, 一步步找呀
### 代码

```java
class Solution {
    public int integerBreak(int n) {
        int[]dp=new int[n+1];
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i-1;j++){
                dp[i]=Math.max(dp[i],Math.max(j*dp[i-j],j*(i-j)));
            }
        }
        return dp[n];
    }
}
```