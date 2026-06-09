这道题可以装换成**0-1背包问题**：给定nums.length个物品和一个容量为halfSum的背包，物品的重量为nums[i]。问最多能装多少物品，装的物品的重量最大值是否恰好等于背包容量？

Dp[i][j]表示背包容量为j时，前i个物品可供选择时，背包最多能装多少重量的物品。每个物品都有装进或不装进背包两种状态。
如果背包容量大于当前物品重量：
Dp[i][j]= max(不装进背包的总量，装进背包的总量），即dp[i][j] = max(dp[i-1][j],nums[i]+dp[i-1][j-nums[i]])
如果背包容量小于当前物品重量：
dp[i][j] = dp[i-1][j]；
以[1,5,11,5]为例，填充dp表格，如下所示：
![捕获.JPG](https://pic.leetcode-cn.com/9b5ffaab87d8f15397f76dc170ace3ef7ebdaa309e8e89f4bd78a541988d6e57-%E6%8D%95%E8%8E%B7.JPG)

Dp[n][w]（最右下角）即为背包能装的物品的最大重量，如果等于背包容量，即为True。

**空间优化：**
只用一维数组,每次从右遍历即可。
状态转移方程式：dp[j] = max(dp[j],nums[i]+dp[j-nums[i]]);

时间复杂度：O(n^2)
空间复杂度：O(n)

代码：

```
    public boolean canPartition(int[] nums) {
        if(nums.length == 0) return false;
        int sum = 0;
        for(int i=0;i<nums.length;i++){
            sum += nums[i];
        }
        if(sum%2 == 1){              //数组和为奇数不满足
            return false;
        }
        int halfSum = sum/2;
        int[] dp = new int[halfSum+1];
        for(int i=0;i<nums.length;i++){
            for(int j=halfSum;j>=1;j--){
                if(j>=nums[i]){
                    dp[j] = Math.max(dp[j],nums[i]+dp[j-nums[i]]);
                    if(dp[j]==halfSum){
                        return true;
                    }
                }
            }
        }
        return false;
    }
```



