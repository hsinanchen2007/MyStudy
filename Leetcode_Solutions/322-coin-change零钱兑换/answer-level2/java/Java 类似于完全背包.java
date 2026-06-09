# 变量说明
- dp[] 价钱为该值时，最少需要的硬币数目
- min 临时变量，记录最小硬币数


# 步骤说明
- 初始化0值
- 对coin数组进行排序
- 对于每一个价钱，对coin数组里每一种钱数进行遍历求解，即若使用这一种面值的钱，最小用几个硬币
- 注意在遍历时，总钱数一定要大于等于当前硬币面值，且若上一个无解，则不能进入这一次循环
- min写入dp[]


```
class Solution {
    public int coinChange(int[] coins, int amount) {
        //dp[] 表示价钱为该值时，最少需要的硬币数目
        int[] dp = new int[amount+1];
        int coinNum = coins.length;
        
        Arrays.sort(coins);
        dp[0] = 0;
        
        for(int i=1; i<=amount; i++)
        {
            int min = 99999;
            for(int k=0; k<coinNum; k++)
            {   
                if(i>=coins[k] && dp[i-coins[k]] != -1)
                    min = Math.min(min,dp[i-coins[k]]+1);
            }
            
            if(min==99999)
                dp[i] = -1;
            else
                dp[i] = min;
        }
        
        return dp[amount];
        
    }
}
```
