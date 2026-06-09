### 解题思路
这是一个经典的完全背包问题，套用完全背包问题的模板即可。

### 代码

```java
class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount+1];
        dp[0] = 1;
        for(int cur : coins){
            for(int j = cur;j<=amount;j++){
                    dp[j] += dp[j-cur];
            }
        }
        return dp[amount];
    }
}
```