### 解题思路

定义安全的点：路径终点，也就是出度为0的点

定义最终安全的点：从起始节点开始，可以沿某个路径到达终点，那么起始节点就是最终安全的点。

1. 找到出度为0的顶点，这些点是安全的点
2. 逆向删除以出度为0的顶点为弧头的边，弧尾的出度减一
3. 重复上面两步，直到不存在出度为0的顶点

### 代码

```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outDegree(n, 0); // 维护出度
        vector<vector<int>> revGraph(n, vector<int>{});
        vector<int> ans;
        for (int i =0; i < n; i++){
            outDegree[i] = graph[i].size();
            for (auto &end : graph[i]){
                revGraph[end].push_back(i);
            }
        }
        queue<int> q;
        for (int i =0; i< n ; i++){
            if (outDegree[i] == 0) q.push(i);
        }
        while (!q.empty()){
            int f = q.front();
            ans.push_back(f);
            q.pop();
            for (auto start: revGraph[f]){
                outDegree[start]--;
                if (outDegree[start] == 0) q.push(start);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```