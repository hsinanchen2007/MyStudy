### 解题思路
首先我们可以很容易的想到撞鸭dp,$dp[i][sta]$表示当前在$i$点,已经访问了的点集为$sta$,所需要的最少步数.
显然转移方程为:$dp[i][sta]=min(dp[i][sta],dp[k][sta+(1<<k)]+value(i,k))$
然后我们可以用$Floyd$处理出任意两点间的距离.
**NOTE:**注意转移时的枚举顺序,因为很久没写撞鸭dp了,想到了撞鸭dp后把枚举顺序搞反了,应该先枚举状态再枚举当前点.

### 代码

```cpp
class Solution
{
public:
    int mp[15][15];
    int dp[15][1 << 12];
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        if (graph[0].size() == 0)
            return 0;
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < n; i++)
        {
            for (auto v : graph[i])
                mp[i][v] = mp[v][i] = 1;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        continue;
                    if (mp[i][k] && mp[k][j])
                    {
                        if (mp[i][j] == 0)
                            mp[i][j] = mp[i][k] + mp[k][j];
                        else
                            mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                    }
                }
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < n; i++)
            dp[i][1 << i] = 0;
        for (int j = 1; j < (1 << n); j++)
        {
            for (int i = 0; i < n; i++)
                if ((j >> i & 1) == 1)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (mp[i][k] && (j >> k & 1) == 0)
                        {
                            dp[k][j + (1 << k)] = min(dp[k][j + (1 << k)], dp[i][j] + mp[i][k]);
                        }
                    }
                }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
            ans = min(ans, dp[i][(1 << n) - 1]);
        return ans;
    }
};
```