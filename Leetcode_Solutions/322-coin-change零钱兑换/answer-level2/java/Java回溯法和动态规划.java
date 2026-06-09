### 解题思路
如果简单地使用回溯法求出所有的情况必然会超时，所以不能一个个地拿硬币，同时要注意剪枝；
用动态规划求解的话就很简单，但前提是想得到，先建立一个dp数组保存之前计算的结果，定义dp[i]为金额为i时兑换零钱的最小数量，由此，对于每一个面额c的零钱有：
`dp[i] = dp[i-c]+1, if i-c可以兑换成功，即dp[i-c]!=-1`
基于以上的分析，只需要从头遍历dp数组，同时修改dp[i]为兑换零钱的最小数量，最终dp[amount]就是答案：

### 代码
回溯算法（DFS）：
```java
class Solution {
    int result = Integer.MAX_VALUE;
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        backtrack(coins,coins.length-1,amount,0);
        return result==Integer.MAX_VALUE?-1:result;
    }
    public void backtrack(int[] coins,int i, int res, int count){
        if(res==0){
            result = Math.min(result,count);
            return ;
        }
        if(i<0 || res<0) return ;
        int k = res/coins[i];
        for(int start=k;start>=0;start--){
            if(count+start>result) break;
            backtrack(coins,i-1,res-start*coins[i],count+start);
        }
    }
}
```
动态规划：
```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount+1];
        for(int i=1;i<=amount;i++){
            int min = Integer.MAX_VALUE;
            for(int c: coins){
                if(i>=c && dp[i-c]!=-1){
                    min = Math.min(min,dp[i-c]+1);
                }
            }
            dp[i] = min!=Integer.MAX_VALUE?min:-1;
        }
        return dp[amount];
    }
}
```