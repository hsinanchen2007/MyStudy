### 解题思路
队列存储状态（到某个节点时已访问的节点集合），对应一个二维数组存储这个状态的路径长度。

### 代码

```cpp
class Solution {
public:
struct State {
    // 已访问的节点，位表示
    int visited;
    // 当前节点索引
    int index;
    State(int v, int i) : visited(v), index(i) {}

};
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() == 0) return 0;
        int node_num = graph.size();

        // 访问到当前节点时，已访问的节点的最短路径
        // 行表示已访问的节点（位表示法），列表示当前节点索引
        vector<vector<int>> dist((1 << node_num), vector<int>(node_num, INT_MAX));

        // 终止状态：所有节点均已被访问，所有位都是1
        int all_visited = (1<<node_num) - 1;

        queue<State> q;
        for (int i = 0; i < node_num; ++i) {
            // i已被访问
            q.push(State((1 << i), i));
            // 当前节点为i，已访问i节点的路径为0
            dist[1<<i][i] = 0;
        }

        while(!q.empty()) {
            State pre = q.front();
            q.pop();
            int v = pre.visited;
            int d = dist[v][pre.index];
            if (v == all_visited) return d;
            // 从上一状态最后访问节点开始广度扩展
            for (int node : graph[pre.index]) { 
                int v_new = v |(1 << node);
                if (dist[v_new][node] > d + 1) {
                    dist[v_new][node] = d + 1;
                    q.push({v_new, node});
                }
            }
        }
        return INT_MAX;
    }
};
```