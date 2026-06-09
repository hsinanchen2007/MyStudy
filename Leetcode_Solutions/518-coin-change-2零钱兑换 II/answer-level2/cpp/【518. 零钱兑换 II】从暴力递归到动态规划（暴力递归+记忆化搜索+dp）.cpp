## 思路一：暴力递归
尝试，尝试每个硬币的每个可能数量。
### 代码
```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }        
        return ways(coins, 0, amount);
    }
    //可以自由使用coins[index..]组成amount的方法数
    int ways(vector<int>& coins, int index, int amount) {
        if (index == coins.size()) {
            return amount == 0 ? 1 : 0;
        }
        int way = 0;
        for (int i = 0; i * coins[index] <= amount; ++i) {
            int fix = i * coins[index];
            int left = amount - fix;
            way += ways(coins, index + 1, left);
        }
        return way;
    }
};
```

## 思路二：记忆化搜索
**注意：因为可以达到index和amount位置，所以记忆化数组大小+1**
### 代码
```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }        
        vector<vector<int>> map(coins.size()+1, vector<int>(amount+1, -1));
        return ways(coins, 0, amount, map);
    }
    int ways(vector<int>& coins, int index, int amount, vector<vector<int>> &map) {
        if (index == coins.size()) {
            map[index][amount] = amount == 0 ? 1 : 0;
            return amount == 0 ? 1 : 0;
        }
        if (map[index][amount] != -1) {
            return map[index][amount];
        }
        int way = 0;
        for (int i = 0; i * coins[index] <= amount; ++i) {
            int fix = i * coins[index];
            int left = amount - fix;
            way += ways(coins, index + 1, left, map);
            
        }
        map[index][amount] = way;
        return way;
    }
};
```

## 思路三：动态规划
根据暴力递归修改为动态规划（row表示coins下标，am表示钱数）
![image.png](https://pic.leetcode-cn.com/a4ecabdddc36c0c2f3c206dacb0ea2b5f3b7eacab7f5c3a7a96f5ba0edb98c41-image.png)

### 代码
```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }  
        int row = coins.size();
        vector<vector<int>> dp(row+1, vector<int>(amount+1));
        //初始状态，设置第row+1行和第一列
        dp[row][0] = 1;
        for (int i = 0; i < row; ++i) {
            dp[i][0] = 1;
        }
        //其它位置从下到上，从左到右，依次填表
        for (int i = row - 1; i >= 0; --i) {
            for (int j = 0; j <= amount; ++j) {
                int way = 0;
                for (int k = 0; k * coins[i] <= j; ++k) {
                    way += dp[i + 1][j - k * coins[i]];
                }
                dp[i][j] = way;
            }
        }   
        return dp[0][amount];
    }
};
```
#### 优化代码
```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }  
        int row = coins.size();
        vector<vector<int>> dp(row+1, vector<int>(amount+1));
        dp[row][0] = 1;
        for (int i = 0; i < row; ++i) {
            dp[i][0] = 1;
        }
        for (int i = row - 1; i >= 0; --i) {
            for (int j = 0; j <= amount; ++j) {
                dp[i][j] = dp[i+1][j];
                if (j - coins[i] >= 0) {
                    dp[i][j] += dp[i][j-coins[i]];
                }
            }
        }   
        return dp[0][amount];
    }
};
```



