### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int v[4] = {1, 5, 10, 25};
        for (int i = 0; i < 4; i ++)
            for (int j = v[i]; j <= n; j ++)
                dp[j] = (dp[j] + dp[j - v[i]]) % MOD;
        return dp[n];
    }

private:
    const static int MOD = 1e9 + 7;
};
```