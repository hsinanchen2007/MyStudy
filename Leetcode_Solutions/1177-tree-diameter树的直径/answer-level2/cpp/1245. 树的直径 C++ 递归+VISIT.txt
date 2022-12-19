### 解题思路
类似题目 ：Q124. 二叉树中的最大路径和
不同点：任意节点不是2条路径，而是N叉树，因此每个节点求路径最大有两种情况：
1）以该节点为根：从该节点N条分支中，取最大的两条求和，
2）不以该节点为根：取当前节点与N条分支中最大的路径求和，向上返回，作为路径的一部分

### 代码

```cpp
class Solution {
public:
    int maxvalue = 0;
    unordered_map<int, vector<int>> pathmap;
    unordered_map<int, int> visit;

    int dfs(int node)
    {
        visit[node] = 1;
        vector<int> lengths;
        int fisrtmax = 0;
        int secondmax = 0;

        for (auto next : pathmap[node]) {
            if (visit[next] == 1) {
                continue;
            }

            int value = dfs(next);
            if (value > fisrtmax) {
                secondmax = fisrtmax;
                fisrtmax = value;
            }else if(value>secondmax){
                secondmax = value;
            }
        }

        maxvalue = max(maxvalue, fisrtmax + secondmax);
        return fisrtmax + 1;
    }

    int treeDiameter(vector<vector<int>> &edges)
    {
        if (edges.empty() || edges[0].empty()) {
            return 0;
        }

        pathmap.clear();
        visit.clear();
        maxvalue = 0;
        for (auto edge : edges) {
            pathmap[edge[0]].push_back(edge[1]);
            pathmap[edge[1]].push_back(edge[0]);
            visit[edge[0]] = 0;
            visit[edge[1]] = 0;
        }

        dfs(edges[0][0]);

        return maxvalue;
    }
};
```