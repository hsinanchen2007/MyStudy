### 解题思路
问题本质上是依赖图是否可以拓扑化，即判断图中是否有环。
首先寻找图中所有入度为0的节点，如果没有，那肯定有环。之后通过BFS判断是否有环，即判断是否有节点进入队列的次数多于课程数，但这仅对应与环的起始节点不是根节点的情况，如果有一个连通分量本身是一个环的话则该环中的节点不会进入队列。所以BFS判断图中有环的充要条件是所有节点至少进过一次队列，并且不会进入numCourses次。

### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool* root = new bool[numCourses];
        for (int i = 0; i < numCourses; i++)
            root[i] = true;
        
        unordered_map<int, vector<int>> adj;

        for (auto tmp : prerequisites) {
            root[tmp[0]] = false;
            adj[tmp[1]].push_back(tmp[0]);
        }

        queue<int> q;
        int* mark = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            if (root[i]) {
                q.push(i);
                mark[i] = 1;
            }
            else
                mark[i] = 0;
        }

        if (q.empty())
            return false;

        bool result = true;
        while (!q.empty() && result) {
            int tmp = q.front();
            q.pop();
            if (adj.find(tmp) != adj.end()) {
                for (auto i : adj[tmp]) {
                    mark[i]++;
                    q.push(i);
                    if (mark[i] > numCourses) {      // 有环
                        result = false;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (mark[i] == 0) {
                result = false;
                break;
            }
        }

        delete []mark;
        delete []root;

        return result;
    }
};
```