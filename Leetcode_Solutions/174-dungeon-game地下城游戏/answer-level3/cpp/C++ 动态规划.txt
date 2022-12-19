# 解法一：
二维动态规划
1，`dp[i][j]`代表从`[i, j]`出发到达终点需要的最小初始血量
状态转移方程为：
2，`dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j])`
3，注意边界情况特殊处理即可，右下角单独计算
时间复杂度O(n^2)
空间复杂度O(n^2)
```C++ []
class Solution {
public:
    using ll = long long;
    const ll INF = INT_MAX;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return -1;
        int R = dungeon.size();
        int C = dungeon[0].size();
        vector<vector<ll> > dp(R, vector<ll>(C, INF));
        dp[R - 1][C - 1] = 1 - min(dungeon[R - 1][C - 1], 0);
        for (int i = R - 1; i >= 0; --i) {
            for (int j = C - 1; j >= 0; --j) {
                if (i == R - 1 && j == C - 1) continue;
                ll down = (i < R - 1) ? dp[i + 1][j] : INF;
                ll right = (j < C - 1) ? dp[i][j + 1] : INF;
                dp[i][j] = min(right, down) - (ll)dungeon[i][j];
                dp[i][j] = max(dp[i][j], 1LL);
            }
        }
        return dp[0][0];
    }
};
```
![image.png](https://pic.leetcode-cn.com/650ea784e973d200fed0fa16da66c9b1616cdfbd4d4e555f5f431bc8df722654-image.png)


# 解法二：
状态压缩动态规划
时间复杂度O(n^2)
空间复杂度O(n)
```C++ []
class Solution {
public:
    using ll = long long;
    const ll INF = INT_MAX;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return -1;
        int R = dungeon.size();
        int C = dungeon[0].size();
        vector<ll> dp(C, INF);
        dp[C - 1] = 1 - min(dungeon[R - 1][C - 1], 0);
        for (int i = R - 1; i >= 0; --i) {
            for (int j = C - 1; j >= 0; --j) {
                if (i == R - 1 && j == C - 1) continue;
                ll right = (j < C - 1) ? dp[j + 1] : INF;
                dp[j] = min(dp[j], right) - (ll)dungeon[i][j];
                dp[j] = max(dp[j], 1LL);
            }
        }
        return dp[0];
    }
};
```

![image.png](https://pic.leetcode-cn.com/e3f9c52a652218a9e5bf3f41c8fd2614b165073b2b551c37e5d2bb098505773b-image.png)
