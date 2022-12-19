### 解题思路
判断是否为有向无环图
(1) 选择一个入度为0的顶点并输出之；
(2) 从网中删除此顶点及所有出边。
循环结束后，若输出的顶点数小于网中的顶点数，则输出“有回路”信息，否则输出的顶点序列就是一种拓扑序列。
### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        int len = numCourses;
        vector<vector<int>> grafh;
        for (int i = 0; i < len; i++) {
            vector<int> tmp(len, 0);
            grafh.push_back(tmp);
        }
        vector<int> indegree(len, 0);
        //邻接矩阵与入度表
        for (auto line : prerequisites) {
            indegree[line[1]]++;
            grafh[line[0]][line[1]] = 1;
        }
        queue<int> q;
        //入度为0的点入队
        for (int i = 0; i < len; i++) {
            if (indegree[i] == 0) {
                indegree[i] = -1;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (int i = 0; i < len; i++) {
                if (indegree[i] == -1) continue;
                if (grafh[top][i] == 1) indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                    indegree[i] = -1;
                }
            }
            numCourses--;
            
        }
        return (numCourses == 0);
    }
};
```