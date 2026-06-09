自底向上，从没有下属的员工一直找到总负责人headID，同时用dp[i]记录路径上所有点的结果，避免后续分支重复遍历。

```c++
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> dp(n, -1);
        dp[headID] = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (informTime[i] != 0) continue;
            ans = max(ans, dfs(manager, informTime, i, dp));
        }
        return ans;
    }

    int dfs(vector<int>& manager, vector<int>& informTime, int i, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        dp[i] = dfs(manager, informTime, manager[i], dp) + informTime[manager[i]];
        return dp[i];
    }
};
```
