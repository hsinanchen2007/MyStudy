### 解题思路
 bfs 效率要高一些 从目标值往开始值找 ，找到返回true 否则false ,再用一个visited 记录走过的节点

### 代码

```cpp
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<bool> visited(n,false);
        queue<int> q;

        q.push(target);
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            if(t==start)  return true;
            if(visited[t]==true) continue;

            visited[t]=true;

            for(int i=0;i<n;i++)
            {
                if(graph[i][1]==t) q.push(graph[i][0]);
            }

        }

        return false;
    }
};
```