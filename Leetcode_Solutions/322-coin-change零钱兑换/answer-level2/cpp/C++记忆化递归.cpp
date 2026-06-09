### 解题思路
参考了一位大佬的想法写的，比较好理解吧，DP实在不会，暂时不想去研究。
![image.png](https://pic.leetcode-cn.com/e2cca69ec01e1063d121734fd5209ff8f7882255e0907cb55a5845fde61b9325-image.png)

### 代码

```cpp
class Solution {
public:
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }
        int min = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] < 0) {
                break;
            }
            int ret = dfs(coins, amount - coins[i]);
            if (ret < min) {
                min = ret + 1;
            }
        }
        memo[amount] = min;
        return memo[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int ans = dfs(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
private:
    map<int, int> memo;
};
```