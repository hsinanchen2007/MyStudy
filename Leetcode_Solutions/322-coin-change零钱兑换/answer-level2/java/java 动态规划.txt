### 解题思路
dp[i] 表示组成金额i的最小硬币数
状态转移方程 dp[i]=min(dp[i-j])+1 j为coins中的值
### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        //dp[i] 表示组成金额i的最小硬币数
        //状态转移方程 dp[i]=min(dp[i-j])+1 j为coins中的值
        if(amount<=0){
            return amount==0?amount:-1;
        }
        int []dp=new int [amount+1];
        for(int i=1;i<=amount;i++){
            int min=-1;
            for(int j=0;j<coins.length;j++){
                if(i-coins[j]>=0){
                    if(dp[i-coins[j]]!=-1){
                        min=(min==-1?dp[i-coins[j]]:Math.min(min,dp[i-coins[j]]));
                    }
                }
            }
            dp[i]=(min==-1?-1:min+1);
        }
        return dp[amount];
    }
}
```