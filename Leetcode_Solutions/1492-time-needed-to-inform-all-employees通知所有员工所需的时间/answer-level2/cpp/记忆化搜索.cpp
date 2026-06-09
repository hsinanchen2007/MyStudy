### 解题思路
记忆化搜索
使用need_time[i]数组记录id为i的员工收到通知所需要的时间
对每个未确定收到通知所需时间的员工进行dfs，再取所有员工收到通知所需时间的最大值即可

### 代码

```cpp
class Solution {
public:
    const int maxn = 10005;
    int need_time[100005];
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i = 0; i < n; i++) need_time[i] = -1;
        need_time[headID] = 0;
        int max_time = 0;
        for(int i = 0; i < n; i++) {
            // 这里减去informTime[i]是因为dfs返回的是员工i的下属收到通知的时间
            if(need_time[i] == -1) need_time[i] = dfs(i, manager, informTime) - informTime[i];
            max_time = max(max_time, need_time[i]);
        }
        return max_time;
    }

    int dfs(int id, vector<int>& manager, vector<int>& informTime) {
        if(need_time[id] != -1) {
            return need_time[id] + informTime[id];
        }
        need_time[id] = dfs(manager[id], manager, informTime);
        return need_time[id] + informTime[id];
    }
};
```