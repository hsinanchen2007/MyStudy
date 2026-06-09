### 动态规划自底向上

乍一看这个问题很像 **[爬楼梯](https://leetcode-cn.com/problems/climbing-stairs)**，对于爬楼梯这个问题来说，最后的结果等于 *前面两阶楼梯的方法数的和*。

类比这一题，把金钱额数amount看作台阶数，硬币值看作每次登的台阶数，求到达amount的最小次数。

对这个例子：
```
输入: coins = [1, 2, 5], amount = 11
dp[11] = min(dp[10],dp[9],dp[6]) + 1

显然我们找到了状态转移方程：
dp[amount] = min(dp[amount-coins[0]], dp[amount-coins[1]]...) + 1
```

#### 代码
```cpp
class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            for(auto elem : coins) {
                if(i >= elem) {
                    dp[i] = min(dp[i], dp[i - elem] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
```

### 递归
类似动态规划，递归求解同样转换为求解子问题最优解，即求解f(11)，需要计算f(6),f(9),f(10);
从其中选择最小值，再加一即可。


![递归](https://pic.leetcode-cn.com/be4c436fbf9257421d38c63af7ad5567ec8732464ee7d493bcc503b692f9f91c)

先来看一个**递归超时**的代码：

```CPP
class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) {
            return 0;
        }   
        // 定义当前问题的最优解
        int res = INT_MAX;
        for(int elem : coins) {
            if(amount - elem > 0) {
                // 计算子问题最优解
                int sub = coinChange(coins, amount - elem);
                // 当前子问题无解, 跳出
                if(sub == -1) {
                    continue;
                }
                // 从所有子问题中获得最优解
                res = min(res, sub + 1);   
            }
        }
        // 不存在最优解返回 -1
        return res == INT_MAX ? -1 : res;
    }
};
```

理解很简单，不过超时了。从上面的递归图谱不难看出，对于子问题的计算，出现了很多重复的情况。这个问题很好解决，用一个数组记录已经计算过的问题就好啦，这个也叫做，记忆搜索。

### 带记忆的递归
```cpp
class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
        // 建立一个数组，初始存储-2，代表没有计算过该问题
        vector<int> vec(amount + 1, -2);
        return coinChange(coins, amount, vec);
    }
  private:
    int coinChange(vector<int>& coins, int amount, vector<int>& vec) {
        if(!amount) {
            return 0;
        }
        // 该问题已经被求解，直接返回
        if(vec[amount] != -2) {
            return vec[amount];
        }
        int res = INT_MAX;
        for(int elem : coins) {
            if(amount - elem < 0) {
                // 计算子问题最优解
                int sub = coinChange(coins, amount - elem, vec);
                // 当前子问题无解, 跳出
                if(sub == -1) {
                    continue;
                }
                // 从所有子问题中获得最优解
                res = min(res, sub + 1);
            }
        }
        // 记录当前问题的最优解
        vec[amount] = (res == INT_MAX) ? -1 : res;
        return vec[amount];
    }
};
```




