### [1335. 工作计划的最低难度](https://leetcode-cn.com/problems/minimum-difficulty-of-a-job-schedule/)

#### 题解

  + 区间预处理 + 动态规划， 时间复杂度 $O(d*n^2)$
  + $dp[i][j]$ 表示 前i天完成j项工作的总困难
  + $dp[i][j] = min(dp[i-1][k] + diff[k+1][j]) , diff[i][j] 代表从i到j的任务的最小难度$
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;
        int diff[310][310] = {0};
        for(int i = 0; i < jobDifficulty.size(); i++)
            {
                diff[i][i] = jobDifficulty[i];
                for(int j = i+1; j < jobDifficulty.size(); j++)
                    diff[i][j] = max(diff[i][j-1], jobDifficulty[j]);
            }
        int dp[10][310];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        for(int i = 0; i < d; i++)
            for(int j = i; j < jobDifficulty.size(); j++)
                {
                if(i == 0) dp[i][j] = diff[0][j];
                else
                    for(int k = i-1; k < j; k++)
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + diff[k+1][j]);
                }
        int res = dp[d-1][jobDifficulty.size()-1];
        return res == 0x3f3f3f3f ? -1 : res;
    }
};
```