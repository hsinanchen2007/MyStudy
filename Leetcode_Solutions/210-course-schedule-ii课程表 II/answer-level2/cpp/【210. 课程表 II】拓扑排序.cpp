### 思路
建立图模型
1. 建立出度和入度
   - 出度：每个点的出度建立二维矩阵
   - 入度：统计每个点的入度数量
2. 将入度为0的边放入队列
3. 从队列中弹出一个点，并将以该点出发的其它点入度减1
   - 如果其它点入度为0，则继续放入队列

### 代码

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        vector<int> res;
        for (auto &a : prerequisites) {
            graph[a[1]].push_back(a[0]);
            ++in[a[0]];
        } 
        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) que.push(i);
        }
        while (!que.empty()) {
            int t = que.front();
            que.pop();
            res.push_back(t);
            for (auto &a : graph[t]) {
                --in[a];
                if (in[a] == 0) que.push(a);
            }
        }
        if (res.size() != numCourses) res.clear();
        return res;
    }
};
```