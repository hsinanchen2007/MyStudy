### 解题思路

和 [课程表 I](https://leetcode-cn.com/problems/course-schedule/) 雷同，只是要记录拓扑排序的结果，同时检测是否有环。

### 代码

```cpp
class Solution {
private:
    vector<int> visited;
    vector<vector<int>> graph;
    vector<int> path;
    int n;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        
        graph.resize(n);
        visited.resize(n);
        
        for(auto pre: prerequisites) {
            int x = pre[0];
            int y = pre[1];
            graph[y].push_back(x);
        }
        
        fill(visited.begin(), visited.end(), -1);           // 未访问
        
        for(int i=0; i<n; i++) {
            if(visited[i] == -1 && !dfs(i)) {
                path.clear();
                return path;
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
    
    bool dfs(int u) {
        visited[u] = 1;                                     // 访问中
        for(int v: graph[u]) {
            if(visited[v] == 1)
                return false;
            else if(visited[v] == -1 && !dfs(v))
                return false;
        }
        visited[u] = 2;                                     // 已访问
        path.push_back(u);
        return true;
    }
};
```