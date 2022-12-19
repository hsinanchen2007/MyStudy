### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
和上台阶问题类似，每次可选1或2或5面值，利用动态规划，
dp方程如下：
dp[i] = min{dp[n-coins[i]]+1}
if i == 0  dp[0] = 0
if i < 0   return -1
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n =(int)coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i =1; i<=amount; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]]+1);
                }
            }
        }
        return dp[amount] == amount+1 ? -1: dp[amount];
    }
};
```