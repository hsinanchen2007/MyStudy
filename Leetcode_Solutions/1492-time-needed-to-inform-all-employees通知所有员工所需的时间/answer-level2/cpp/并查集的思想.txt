直接递归计算即可
```
class Solution {
public:
    void dfs(int* minutes, int index, vector<int>& manager, vector<int>& informTime) {
        if(minutes[manager[index]] == -1) dfs(minutes, manager[index], manager, informTime);
        minutes[index] = minutes[manager[index]] + informTime[manager[index]];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int minutes[n];
        memset(minutes, -1, sizeof(minutes));
        minutes[headID] = 0;

        for(int i = 0; i < n; i++) {
            if(minutes[i] == -1) {
                dfs(minutes, i, manager, informTime);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, minutes[i]);
        }
        return ans;
    }
};
```
