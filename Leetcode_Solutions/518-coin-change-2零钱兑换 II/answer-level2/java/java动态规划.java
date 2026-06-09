### 解题思路
组合数来自上边和左边。

### 代码

```java
class Solution {
    public int change(int amount, int[] coins) {
        if(amount==0) return 1;
        if(coins.length==0) return 0;
        int[][] dp=new int[coins.length][amount+1];
        int sum=0;
        for(int j=1;j<=amount;j++){
            if(j<coins[0]||j%coins[0]!=0) dp[0][j]=0;
            else {
                dp[0][j]=1;
            }
        }
        for(int i=1;i<dp.length;i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i]) dp[i][j]=dp[i-1][j];
                else {
                    if(j-coins[i]==0) dp[i][j]=dp[i-1][j]+1;//刚够
                    else dp[i][j]=dp[i][j-coins[i]]+dp[i-1][j];
                }
            }
        }
        return dp[dp.length-1][amount];
    }
}
```