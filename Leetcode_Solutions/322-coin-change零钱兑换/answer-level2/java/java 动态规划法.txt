
![批注 2020-02-09 121254.png](https://pic.leetcode-cn.com/9babb27114ff6ee1827e8ac5a4e4e5f872519e09995ec0627b39f71c26ac0c3c-%E6%89%B9%E6%B3%A8%202020-02-09%20121254.png)

### 解题思路
空间换时间的动态规划法，对于金额i，最后一次取的货币金额可能是coins中的一种，
那么找到dp[i]=dp[i-coins[j]]+1中最小的一种即为dp[i]。
还有一种情况是无法达到金额i，那么给dp[i]一个无效值，并最后添加判断即可。

### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp=new int[amount+1];
        int i,j;
        for(i=1;i<=amount;i++){
            dp[i]=10*amount;
            for(j=0;j<coins.length;j++){
                if(i-coins[j]<0)continue;
                if(dp[i]>dp[i-coins[j]]+1)dp[i]=dp[i-coins[j]]+1;
            }
        }
        if(dp[amount]<=amount)return dp[amount];
        else return -1;
    }
}
```