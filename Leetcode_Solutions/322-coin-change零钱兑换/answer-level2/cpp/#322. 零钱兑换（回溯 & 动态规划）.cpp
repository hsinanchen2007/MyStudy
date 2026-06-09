### 回溯+备忘录
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<vector<bool>> visited(amount+1, vector<bool>(amount+1, false)); // 备忘录
        backtrack(coins, 0, amount, visited);
        if (minCount == INT_MAX) minCount = -1;
        return minCount;
    }

private:
    void backtrack(vector<int>& coins, int round, int remain, vector<vector<bool>> &visited) {
        if (remain == 0) {
            minCount = min(minCount, round);
            return;
        }
        if (round >= minCount) return;    // 剪枝
        visited[round][remain] = true;
        for (const int &coin: coins) {
            if (remain-coin >= 0 && !visited[round+1][remain-coin]) {  // 剪枝
                backtrack(coins, round+1, remain-coin, visited);
            }
        }
    }

private:
    int minCount = INT_MAX;
};
```
---


### 动态规划

#### 状态转移方程
```cpp
f(n) = min(f(n-coins[0]), f(n-coins[1]), ... ,f(n-coins[size-1])) + 1
```
#### 递归形式
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        F.resize(amount + 1, 0);
        return dp(coins, amount);
    }
    
private:
    int dp(vector<int> coins, int remain) {
        if (remain == 0) return 0;
        if (remain < 0) return -1;
        if (F[remain] != 0) return F[remain];
        int minRes = INT_MAX;
        for (const int &coin: coins) {
            int res = dp(coins, remain-coin);
            if (res != -1 && res < minRes) {
                minRes = res;
            }
        }
        F[remain] = (minRes == INT_MAX ? -1 : minRes+1);
        return F[remain];
    }
    
private:
    vector<int> F;
};
```

#### 迭代形式
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int minVal = INT_MAX;
            for (const int &coin: coins) {
                if (i >= coin) minVal = min(minVal, dp[i-coin]);
            }
            if (minVal != INT_MAX) dp[i] = minVal + 1;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
```