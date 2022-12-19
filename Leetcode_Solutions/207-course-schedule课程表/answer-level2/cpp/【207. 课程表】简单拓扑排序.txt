## 思路：拓扑排序
### 代码
时间复杂度：O(N+M)，N和M为节点数量和临边数量
```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //1. 构建邻接表
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);//表示入度
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++degree[p[0]];
        }
        //2. 将入度为0节点入队列
        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) {
                que.push(i);
            }
        }
        //3. 弹出一个队列元素，并依次将以当前点为出度的的领节点入度减一，若为0则入队列，最后判断是否将所有节点从图中删除。
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            --numCourses;
            for (auto next : adj[cur]) {
                if (--degree[next] == 0) {
                    que.push(next);
                }
            }
        }
        return numCourses == 0;
    }
};
```
