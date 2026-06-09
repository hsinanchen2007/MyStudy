### 解题思路
参考：`https://leetcode-cn.com/problems/dungeon-game/solution/c-dp-10xing-by-pjpj/`
![在这里插入图片描述](https://pic.leetcode-cn.com/d34a084387168c54bd919d757d3858ab5508b62a574c384a6d4797fb5fdfe053.png)
### 代码

```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int>dp(n + 1, INT_MAX/10);
        dp[n-1] = 1;
        for(int i = m - 1; i >= 0; i--)
        {
            dp[n-1] = max(1, dp[n-1] - dungeon[i][n-1]);
            for(int j = n - 2; j >= 0; j--)
            {
                dp[j] = max(1, (min(dp[j], dp[j+1]) - dungeon[i][j]));
            }
        }
        return dp[0];
    }
};
```