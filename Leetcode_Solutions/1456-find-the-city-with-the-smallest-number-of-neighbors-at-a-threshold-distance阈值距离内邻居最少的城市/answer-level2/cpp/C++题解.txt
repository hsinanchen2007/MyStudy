### [1334. 阈值距离内邻居最少的城市](https://leetcode-cn.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solution/)

#### 题解

  + 利用floyd算法统计出点与点之间的最短距离
  + 利用distanceThreshold进行筛选出符合题目要求的解
  + 还可以考虑用其他最短路算法，Bellmanford，spfa，dijkstra 求最短距离
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dp[110][110];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        for(int i = 0; i < edges.size(); i++)
            dp[edges[i][0]][edges[i][1]] = dp[edges[i][1]][edges[i][0]] = edges[i][2];
        //  注意k是第一层循环，dp[k][i][j] 表示前k个点作为插点能达到的最短距离
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dp[i][j] =  min(dp[i][j], dp[i][k] + dp[k][j]);

        int count[110] = {0};
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(dp[i][j] <= distanceThreshold) count[i]++, count[j]++;

        int minc = 0x3f3f3f3f, res;
        for(int i = 0; i < n; i++)
            if(count[i] <= minc)  res = i, minc = count[i];
        return res;
    }
};
```
