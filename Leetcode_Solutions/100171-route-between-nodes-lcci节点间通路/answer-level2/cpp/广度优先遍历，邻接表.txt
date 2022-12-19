见注释

```
class Solution {
   public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start,
                               int target) {
        // 创建邻接表
        vector<vector<int>> g(n);
        for (vector<int> v : graph) {
            g[v[0]].push_back(v[1]);
        }

        vector<bool> visit(n, false);
        queue<int> q;
        // 从 start 开始
        q.push(start);
        visit[start] = true;
        while (!q.empty()) {
            int t = q.front();
            q.pop();

            // 找到了，直接返回
            if (t == target) return true;

            // 设置当前节点已访问并将未访问的邻接节点加入队列
            visit[t] = true;
            for (int next : g[t]) {
                if (next == target) return true;
                if (!visit[next]) q.push(next);
            }
        }

        return false;
    }
};
```
