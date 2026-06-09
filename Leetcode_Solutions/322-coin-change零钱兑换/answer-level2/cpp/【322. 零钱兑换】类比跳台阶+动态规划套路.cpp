## 思路一：类比跳台阶
把钱数amount当作台阶数，硬币值当作每次可跳的台阶数，求到达amount的最小跳数dp[amount]。
dp[amount]最小值为到达前面几个台阶数的最小值加1，如：dp[11] = min(dp[10], dp[9], dp[6]) + 1
初始值：设到达每级台阶最小为：dp[i] = amount+1 ，dp[0] = 0；
如果硬币值小于当前钱数 i，则遍历不同硬币数coins[j]，取min(dp[i], dp[i-coin[j]] + 1)。
最后，如果dp[amount] == MAX，则返回-1，否则返回当前dp[amount]。

### 代码
时间复杂度：O(amount*n)
空间复杂度：O(amount)
```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }                
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```

## 思路二：暴力递归（超时）
对于每种硬币，求子问题amount-coins[i]的最优解。
如果求f(n)表示钱数n最少硬币数，如果求f(11)，需要求f(10), f(9)，f(6)，存在 **大量重复计算**
![image.png](https://pic.leetcode-cn.com/f04ceecaef4980d5115f28eda8366c139844135d360dd8c019ec113ee79c345c-image.png)

### 代码
```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        int res = INT_MAX;
        for (auto coin : coins) {
            //当前金额不可用
            if (amount - coin < 0) {
                continue;
            }
            int sub = coinChange(coins, amount - coin);
            //子问题无解
            if (sub == -1) {
                continue;
            }
            res = min(res, sub + 1);
        }
        return res == INT_MAX ? -1 : res;
    }
};
```

## 思路三：记忆搜索
将已经算过的值保存，每次计算前进行查询。
### 代码
```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> map(amount+1, -2);
        return coinHelper(coins, amount, map);
    }
    
    int coinHelper(vector<int>& coins, int amount, vector<int>& map) {
        if (amount == 0) {
            return 0;
        }
        if (map[amount] != -2) {
            return map[amount];
        }
        int res = INT_MAX;
        for (auto coin : coins) {
            //当前金额不可用
            if (amount - coin < 0) {
                continue;
            }
            int sub = coinHelper(coins, amount - coin, map);
            //子问题无解
            if (sub == -1) {
                continue;
            }                
            res = min(res, sub + 1);                 
        }        
        map[amount] = (res == INT_MAX) ? -1 : res;
        return map[amount];
    }
};
```

## 思路四：动态规划
将map替换为dp表
### 代码
```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto coin : coins) {
                if (i - coin < 0) {
                    continue;
                }
                int sub = 1 + dp[i-coin];
                dp[i] = min(dp[i], sub);
            }            
        }        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```

