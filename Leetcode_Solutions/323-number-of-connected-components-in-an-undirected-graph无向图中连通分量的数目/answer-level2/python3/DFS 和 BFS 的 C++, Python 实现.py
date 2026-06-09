## 解法一: DFS

**Python 实现:**
```py
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        def dfs(graph, visited, node):
            for adj_node in graph[node]:
                if not visited[adj_node]:
                    visited[adj_node] = True
                    dfs(graph, visited, adj_node)

        graph = dict()
        for i in range (n):
            graph[i] = dict()
        for edge in edges:
            graph[edge[0]][edge[1]] = 1;
            graph[edge[1]][edge[0]] = 1;
        visited = [False] * n
        connected = 0
        for node in range(n):
            if not visited[node]:
                visited[node] = True
                connected += 1
                dfs(graph, visited, node)
        return connected
```


**C++ 实现:**
```cpp
class Solution {
    void dfs(std::unordered_map<int, std::unordered_set<int>> &graph, std::vector<bool> &visited, int node) {
        for (auto &adj_node : graph[node]) {
            if (!visited[adj_node]) {
                visited[adj_node] = true;
                dfs(graph, visited, adj_node);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::unordered_set<int>> graph;
        for (int i = 0; i < n; i++) graph[i] = std::unordered_set<int>{};
        for (auto &edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        std::vector<bool> visited(n, false); // 访问数组, 记录访问过的节点
        int connect = 0; // 记录连通分量个数
        for (auto &node : graph) {
            if (!visited[node.first]) {
                connect++;
                visited[node.first] = true;
                dfs(graph, visited, node.first); // 深度遍历
            }
        }
        return connect;
    }
};
```

## 解法二: BFS

**Python 实现:**
```py
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:        
        graph = dict()
        for i in range (n):
            graph[i] = dict()
        for edge in edges:
            graph[edge[0]][edge[1]] = 1;
            graph[edge[1]][edge[0]] = 1;
        visited = [False] * n
        connected = 0
        for node in range(n):
            if not visited[node]:
                visited[node] = True
                connected += 1
                graph_q = [node] # 初始化 BFS 队列
                while (graph_q): # 循环直至队列为空
                    cur_node = graph_q.pop(0)
                    for adj_node in graph[cur_node]: # 所有未遍历过的邻接节点入队列
                        if not visited[adj_node]:
                            visited[adj_node] = True
                            graph_q.append(adj_node)
        return connected
````

**C++ 实现:**
```cpp
class Solution {

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::unordered_set<int>> graph;
        for (int i = 0; i < n; i++) graph[i] = std::unordered_set<int>{};
        for (auto &edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        std::vector<bool> visited(n, false); // 访问数组, 记录访问过的节点
        int connected = 0; // 记录连通分量个数

        for (auto &node : graph) {
            if (!visited[node.first]) {
                connected++;
                visited[node.first] = true;
                std::queue<int> graph_q; // BFS 队列
                graph_q.push(node.first); // 初始化节点入队列
                while (!graph_q.empty()) { // BFS 直至队列为空
                    int cur_node = graph_q.front(); graph_q.pop();
                    for (auto &adj_node : graph[cur_node]) { // 邻接节点入队列
                        if (!visited[adj_node]) {
                            visited[adj_node] = true;
                            graph_q.push(adj_node);
                        }
                    }
                }
            }
        }
        return connected;
    }
};
```
