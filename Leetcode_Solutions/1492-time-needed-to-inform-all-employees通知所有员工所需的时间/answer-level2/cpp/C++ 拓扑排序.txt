## 代码
```cpp
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // 拓扑排序求解最长路径
        vector<int> in(n, 0); // 入度统计
        vector<int> cost(n, 0); // 子节点最长通知时间统计
        for (auto m : manager) {
            if (m != -1)
                in[m]++;
        }
        queue<int> work_queue; // 入度为0时入队处理
        for (int i = 0; i < n ;i++) {
            if (!in[i]) {
                work_queue.push(i);
            }
        }
        while (!work_queue.empty()) {
            auto cur = work_queue.front();
            work_queue.pop();
            auto m = manager[cur];
            if (m != -1) {
                in[m]--;
                if (!in[m])
                    work_queue.push(m);
                auto cc = cost[cur] + informTime[cur];
                if (cc > cost[m])
                    cost[m] = cc;
            }
        }
        return cost[headID] + informTime[headID];
    }
};
```