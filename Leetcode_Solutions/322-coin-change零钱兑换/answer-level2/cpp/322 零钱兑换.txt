### 解题思路
解题思路都写在了注释里面，请直接撸代码吧。

### 代码

```cpp
//动态规划的本质就是数学归纳法
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        if(amount < 0 || size < 0){
            return -1;
        }
        vector<int> dp(amount+1,amount+1);//因为下面的外层循环是要从1走到amount的，所以dp的数组大小应该是amount+1；因为总金额为amount所需的硬币数量最多也就是amount个（全部使用面值为1的硬币），而且我们是想求最小值，所以将dp初始化为amount+1.
        dp[0] = 0;

        for(int i = 1;i <= amount;i++){//i为从1到amount的step，
            for(int j = 0;j < size;j++){//内层循环：从1开始的零钱总额，每一个金额都遍历一遍零钱的种类
                if(coins[j] <= i){//只要当前一种的零钱不大于当前的金额就去执行动态规划转移方程
                    dp[i] = min(dp[i],dp[i - coins[j]] + 1);//取(当前总金额的最少硬币数量)和(去除当前硬币金额(i-coin[j])的总金额的最少硬币数量加上1个当前硬币)中较小的那个值作为当前总金额最小硬币数量。
                }
            }
        }

        return (dp[amount] > amount) ? -1 : dp[amount];
    }

    bool static cmp(int a,int b){//这个方法在这里没啥用，如果用到了sort函数，那么cmp可以作为第三个参数
        return a > b;
    }
};
```