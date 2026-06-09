# 零钱兑换
# 思路
- 首先看到这个题，我第一反应就是回溯，利用回溯找到所有满足题意的解集，然后求出子集中长度最小的即可，其实提交之前我已经预感到了执行时间上可能会有问题，但是我还是不死心想试一试哈哈哈，果然超时了。
- 然后我又想其它的办法，在题解中看到了动态规划。我又看了一下题目，发现这不就是一个背包问题嘛，而且是一个完全背包，也就是物品可以重复装。物品就是硬币，物品的重量就是数组中的值，最后要输出的是装满背包的最少硬币数，这里硬币数就是价值，每个硬币的价值都是1。
# 代码
```
class Solution {
    public int coinChange(int[] coins, int amount) {
        if(coins==null||coins.length==0)
        return -1;
        int[] dp=new int[amount+1];
        //因为要恰好装满，题目求的是最小价值，所以把dp初始化为最大的值
        int max=amount+1;
        Arrays.fill(dp,max);
        dp[0]=0;
        for(int coin:coins)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j>=coin)
                dp[j]=Math.min(dp[j],dp[j-coin]+1);
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
}
```
# 复杂度：
- 时间复杂度：O(sn)，其中s是总金额，n是硬币的个数
- 空间复杂度：O(s)。s为总金额。dp数组需要开辟长度为总金额s的空间。
