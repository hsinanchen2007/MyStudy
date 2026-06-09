### 解题思路
这题用BFS/DFS也行，但是性能应该不如并查集

### 代码

```cpp
class Solution {
public:
    void BFS(map<int, vector<int>>& adj, vector<int>& visited, int startPos)
    {
        queue<int> q;
        q.push(startPos);
        while (!q.empty()) {
            int curPos = q.front();
            q.pop();
            /*从邻接表中尝试所有的连接点*/
            for (auto& a : adj[curPos]) {
                if (visited[a] == 0) {
                    visited[a] = 1;
                    q.push(a);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        int ans = 0;
        map<int, vector<int>> adj;//建立邻接表
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        /*从0开始染色*/
        for (int i = 0; i < n; ++i) {
            /*如果为1说明在前面的BFS中已经被染色了，说明是连通的
            如果为0说明前面的BFS无法抵达此位置，说明是独立区域*/
            if (visited[i] == 0) {
                visited[i] = 1;
                BFS(adj, visited, i);
                ++ans;//有几个独立区域就是有几个连通分量
            }
        }

        return ans;
    }
};
```